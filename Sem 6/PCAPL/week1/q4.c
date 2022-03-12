#include<mpi.h>
#include<stdio.h>
#include<ctype.h>

char toggle(char c){
    if(c >= 'a' && c <= 'z'){
        return toupper(c);
    }
    else{
        return tolower(c);
    }
    return c;
}
int main(int argc,char* argv[])
{
	int rank,size;
	char s[5]="HeLLo";
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);

	
    s[rank] = toggle(s[rank]);
	printf("In process %d..string after toggling is %s \n",rank,s);

	MPI_Finalize();
	return 0;

}