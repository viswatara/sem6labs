#include "mpi.h"
#include<stdio.h>
int main(int argc, char * argv[]){
	int rank,size,x;
	
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Status status;
	if(rank==0){
		printf("Enter a value in master process");
		scanf("%d",&x);
		MPI_Ssend(&x,1,MPI_INT,1,1,MPI_COMM_WORLD);
		fprintf(stdout, "I have sent %d from process 0\n",x);
		MPI_Recv(&x,1,MPI_INT,size-1,1,MPI_COMM_WORLD,&status);
		fprintf(stdout, "I have received %d from process %d\n",x,size-1);
	}
	else {

		MPI_Recv(&x,1,MPI_INT,rank-1,1,MPI_COMM_WORLD,&status);
		fprintf(stdout,"I have received %d in process %d\n",x,rank);
		x=x+1;
		if(rank==size-1){
			MPI_Ssend(&x,1,MPI_INT,0,1,MPI_COMM_WORLD);
			
		}
		else{
		MPI_Ssend(&x,1,MPI_INT,rank+1,1,MPI_COMM_WORLD);
		fflush(stdout);
		}
	}
	
	MPI_Finalize();
	return 0;
}

