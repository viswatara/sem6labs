#include"mpi.h"
#include<stdio.h>
#include<string.h>
int main(int argc, char*argv[]){
	int rank, size, N,i,sum=0,sumt=0,cc,B[200];
	char A[200],str[200];
	
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	if(rank==0){
		N=size;
		fprintf(stdout,"Enter string:\n");
		fflush(stdout);
		scanf("%s",str);
		cc=(strlen(str)/N);
	}	
	MPI_Bcast(&cc,1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Scatter(str,cc, MPI_CHAR, A, cc, MPI_CHAR, 0, MPI_COMM_WORLD);
	
	fprintf(stdout,"\nI have recieved %s in process %d\n",A,rank);
	fflush(stdout);
	for(i=0;i<cc;i++){
		if(A[i]=='a'||A[i]=='e'||A[i]=='i'||A[i]=='o'||A[i]=='u') continue;
		else sum++;
	}
	MPI_Gather(&sum,1,MPI_INT,B,1,MPI_INT,0,MPI_COMM_WORLD);
	if(rank==0){
		fprintf(stdout,"\nThe Result gathered in the root:\n");
		fflush(stdout);
		for(i=0;i<N;i++){
			fprintf(stdout,"%d\t",B[i]);
			sumt=sumt+B[i];
		}

		fflush(stdout);
		fprintf(stdout,"\nThe sum calculated in the root:%d \n",sumt);
		fflush(stdout);
	}
	MPI_Finalize();
	return 0;
}