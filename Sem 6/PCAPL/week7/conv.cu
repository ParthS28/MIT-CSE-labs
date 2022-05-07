#include <cuda.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX_MASK_WIDTH 5
#define TILE_SIZE 8

__constant__ int M[MAX_MASK_WIDTH];
__host__ void clearMatrix(int *A, int width)
{
	for (int j = 0; j < width; j++)
		A[j] = 0;
}

__global__ void convolution_basic(int* N,int* M, int* P,int mwidth,int width)
{
	int i=blockIdx.x *blockDim.x+threadIdx.x;
	int pv=0;
	int n_start=i-(mwidth/2);
	for(int j=0;j<mwidth;j++)
	{
		if(n_start+j>=0 && n_start+j<width)
			pv+=N[n_start+j]*M[j];
	}
	P[i]=pv;
}

__global__ void convolution_constant(int* N,int* P,int mwidth,int width)
{
	int i=blockIdx.x *blockDim.x+threadIdx.x;
	int pv=0;
	int n_start=i-(mwidth/2);
	for(int j=0;j<mwidth;j++)
	{
		if(n_start+j>=0 && n_start+j<width)
			pv+=N[n_start+j]*M[j];
	}
	P[i]=pv;
}

__global__ void convolution_shared(int *N,int *P,int Mask_Width,int Width)
{
	int i = blockIdx.x*blockDim.x + threadIdx.x;
	__shared__ int N_ds[TILE_SIZE + MAX_MASK_WIDTH-1];
	int n=(Mask_Width/2);
	int halo_index_left=(blockIdx.x-1)*blockDim.x+threadIdx.x;
	if(threadIdx.x>=blockDim.x-n)
		N_ds[threadIdx.x-(blockDim.x-n)]=(halo_index_left<0)?0:N[halo_index_left];
	N_ds[n+threadIdx.x]=N[blockIdx.x*blockDim.x+threadIdx.x];
	int halo_index_right=(blockIdx.x+1)*blockDim.x+threadIdx.x;
	if(threadIdx.x<n)
		N_ds[n+blockDim.x+threadIdx.x]=(halo_index_right>=Width)?0:N[halo_index_right];
	__syncthreads();
	int Pvalue=0;
	for(int j=0;j<Mask_Width;j++)
		Pvalue+=N_ds[threadIdx.x+j]*M[j];
	P[i]=Pvalue;
}

// __global__ void convolution_shared(int * N, int * P, int mask_width, int width) {
//     int i = blockIdx.x * blockDim.x + threadIdx.x;
//     extern __shared__ int N_shared[];
//     // copy to shared memory
//     N_shared[i] = N[i];
//     __syncthreads();
//     int Pvalue = 0;
//     int N_start_point = i - (mask_width / 2);
//     for (int j = 0; j < mask_width; j++) {
//         if (N_start_point + j >= 0 && N_start_point + j < width) {
//             Pvalue += N_shared[N_start_point + j] * M[j];
//         }
//     }
//     P[i] = Pvalue;
// }

int main(void)
{
	cudaEvent_t start, stop;
	cudaEventCreate( & start);
	cudaEventCreate( & stop);
	int n=7;
	int size=n*sizeof(int);
	int* a=(int*)malloc(size);
	int* p=(int*)malloc(size);
	for(int i=0;i<n;i++)
		a[i]=i+1;
	int x=5;
	int size1=x*sizeof(int);
	int* ma=(int*)malloc(size1);
	for(int i=0;i<x;i++)
		ma[i]=rand()%11;
	printf("Original array: \n");
	for(int i=0;i<n;i++)
	printf("%d\n",a[i]);
	printf("Mask array: \n");
	for(int i=0;i<x;i++)
		printf("%d\n",ma[i]);

	int*d_a;
	int* d_ma;
	int* d_p;
	cudaMalloc((void **)&d_a, size);
	cudaMalloc((void **)&d_ma, size1);
	cudaMalloc((void **)& d_p,size);
	cudaMemcpy(d_a, a, size, cudaMemcpyHostToDevice);
	cudaMemcpy(d_ma, ma, size1, cudaMemcpyHostToDevice);
	cudaMemcpyToSymbol(M,ma,x*sizeof(int));
	cudaEventRecord(start);
	convolution_basic<<<1,n>>>(d_a,d_ma,d_p,x,n);
	cudaEventRecord(stop);
	cudaMemcpy(p, d_p, size, cudaMemcpyDeviceToHost);
	cudaEventSynchronize(stop);
	float milliseconds = 0;
	cudaEventElapsedTime( & milliseconds, start, stop);
	printf("Final array from basic:\n");
	for(int i=0;i<n;i++)
		printf("%d\n",p[i]);
	printf("\n");
	printf("Time to taken for 1D convolution kernel for M is %f ms\n",milliseconds);
	clearMatrix(p, size);
	cudaEventRecord(start);
	convolution_constant<<<1,x>>>(d_a,d_p,x,n);
	cudaEventRecord(stop);
	cudaMemcpy(p, d_p, size, cudaMemcpyDeviceToHost);
	cudaEventSynchronize(stop);
	milliseconds = 0;
	cudaEventElapsedTime( & milliseconds, start, stop);
	printf("Final array from constant: \n");
	for(int i=0;i<n;i++)
	printf("%d\n",p[i]);
	printf("\n");
	printf("Time to taken for 1D convolution kernel with constant memory for M is %f ms\n", milliseconds);
	clearMatrix(p, size);

	cudaEventRecord(start);
	convolution_shared<<<1,x>>>(d_a,d_p,x,n);
	cudaEventRecord(stop);
	cudaMemcpy(p, d_p, size, cudaMemcpyDeviceToHost);
	cudaEventSynchronize(stop);
	milliseconds = 0;
	cudaEventElapsedTime( & milliseconds, start, stop);
	printf("Final array from constant: \n");
	for(int i=0;i<n;i++)
	printf("%d\n",p[i]);
	printf("\n");
	printf("Time to taken for 1D convolution kernel with shared memory for M is %f ms\n", milliseconds);
	cudaFree(d_a);
	cudaFree(d_p);
	cudaFree(d_ma);
	return 0;
}