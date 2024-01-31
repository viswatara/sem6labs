#include"mpi.h"
#include<stdio.h>

int main(int argc, char*argv[]){
	int rank, size, N,i,m;
	float avg=0,avgt=0,sum=0,sumt=0,B[200], A[200],c[200];
	
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	if(rank==0){
		N=size;
		fprintf(stdout,"Enter M value:\n");
		scanf("%d",&m);
		fflush(stdout);
		fprintf(stdout,"Enter %d values:\n",N*m);
		fflush(stdout);
		for(i=0;i<(m*N);i++){
			scanf("%f",&A[i]);
		}
	}
	MPI_Bcast(&m, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Scatter(A,m,MPI_FLOAT,&c,m,MPI_FLOAT,0,MPI_COMM_WORLD);
	fprintf(stdout,"\nI have recieved in process %d\n",rank);
	for(i=0;i<m;i++){
	     printf("%.2f ",c[i]);
	     sum=sum+c[i];  
	}
	fflush(stdout);
	avg=sum/m;
	MPI_Gather(&avg,1,MPI_FLOAT,B,1,MPI_FLOAT,0,MPI_COMM_WORLD);
	if(rank==0){
		fprintf(stdout,"\nThe Result gathered in the root:\n");
		fflush(stdout);
		for(i=0;i<N;i++){
			fprintf(stdout,"%.2f\t",B[i]);
			sumt=sumt+B[i];
		}
		avgt=sumt/N;
		fflush(stdout);
		fprintf(stdout,"\nThe sum calculated in the root:%.2f \n",sumt);
		fflush(stdout);
	}
	MPI_Finalize();
	return 0;
}