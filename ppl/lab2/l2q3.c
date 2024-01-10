#include "mpi.h"
#include<stdio.h>
int main(int argc, char * argv[]){
	int rank,size,x;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	int array[size];
	MPI_Status status;
	int len=96+size;
	int buffer[len];
	MPI_Buffer_attach(buffer,len);
	if(rank==0){
		for(int i=0;i<size;i++){
			printf("Enter array[%d]\n",i);
			scanf("%d",&array[i]);
		}
		for(int i=1;i<size;i++){
			MPI_Bsend(&array[i],1,MPI_INT,i,1,MPI_COMM_WORLD);
			fprintf(stdout, "I have sent %d from process 0\n",array[i]);
		}
		
		fflush(stdout);
	}
	else if(rank%2==0){
		MPI_Recv(&buffer[rank],1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
		fprintf(stdout,"I have received %d in slave process %d. Square is %d\n",buffer[rank],rank,buffer[rank]*buffer[rank]);
		fflush(stdout);
		}
	else{
			MPI_Recv(&buffer[rank],1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
			fprintf(stdout,"I have received %d in slave process %d. Cube is %d\n",buffer[rank],rank,buffer[rank]*buffer[rank]*buffer[rank]);
		fflush(stdout);
	}
	MPI_Buffer_detach(buffer,&len);
	MPI_Finalize();
	return 0;
}