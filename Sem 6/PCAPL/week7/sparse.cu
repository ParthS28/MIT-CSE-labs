#include<stdio.h>
#include<stdlib.h>
#include"cuda_runtime.h"
#include"device_launch_parameters.h"

__global__ void func(int num_rows,int *data,int *col_index,int *row_ptr,int *x,int *y)
{
	int row=threadIdx.x;
	if(row<num_rows)
	{
		int dot=0;
		int row_start=row_ptr[row];
		int row_end=row_ptr[row+1];
		for(int i=row_start;i<row_end;i++)
			dot+= data[i]*x[col_index[i]];
		y[row]=dot;
	}
}

int main()
{
	int n;
	printf("Enter size: ");
	scanf("%d",&n);
	int y[n],row_ptr[n+1];
	int ipmat[n][n];
	printf("Enter matrix: \n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			scanf("%d",&ipmat[i][j]);
	}
	int x[n];
	printf("Enter x matrix: \n");
	for(int i=0;i<n;i++)
		scanf("%d",&x[i]);
	int nonzerocount=0;
	for(int i=0;i<n;i++)
	{
		row_ptr[i]=nonzerocount;
		for(int j=0;j<n;j++)
		{
			if(ipmat[i][j]!=0)
				nonzerocount++;
			printf("%d\t",ipmat[i][j]);
		}
		printf("\n");
	}
	row_ptr[n]=nonzerocount;
	int data[nonzerocount],col_index[nonzerocount];
	int k=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(ipmat[i][j]!=0)
			{
				data[k]=ipmat[i][j];
				col_index[k++]=j;
			}
		}
	}
	printf("\ndata array\t");
	for(int i=0;i<nonzerocount;i++)
		printf("%d\t",data[i]);
	printf("\ncol_index array\t");
	for(int i=0;i<nonzerocount;i++)
		printf("%d\t",col_index[i]);
	printf("\nrow_ptr array\t");
	for(int i=0;i<=n;i++)
		printf("%d\t",row_ptr[i]);
	printf("\nvector X\t");
	for(int i=0;i<n;i++)
		printf("%d\t",x[i]);
	int *d_data,*d_col_index,*d_row_ptr,*d_x,*d_y;

	cudaMalloc((void**)&d_data,nonzerocount*sizeof(int));
	cudaMalloc((void**)&d_col_index,nonzerocount*sizeof(int));
	cudaMalloc((void**)&d_row_ptr,(n+1)*sizeof(int));
	cudaMalloc((void**)&d_x,n*sizeof(int));
	cudaMalloc((void**)&d_y,n*sizeof(int));
	cudaMemcpy(d_data,data,nonzerocount*sizeof(int),cudaMemcpyHostToDevice);
	cudaMemcpy(d_col_index,col_index,nonzerocount*sizeof(int),cudaMemcpyHostToDevice);
	cudaMemcpy(d_row_ptr,row_ptr,(n+1)*sizeof(int),cudaMemcpyHostToDevice);
	cudaMemcpy(d_x,x,n*sizeof(int),cudaMemcpyHostToDevice);
	
	func<<<1,n>>>(n,d_data,d_col_index,d_row_ptr,d_x,d_y);
	cudaMemcpy(y,d_y,n*sizeof(int),cudaMemcpyDeviceToHost);
	printf("\nresult\t\t");
	for(int i=0;i<n;i++)
		printf("%d\t",y[i]);
	printf("\n");
	
	cudaFree(d_data);
	cudaFree(d_col_index);
	cudaFree(d_row_ptr);
	cudaFree(d_x);
	cudaFree(d_y);
	return 0;
}