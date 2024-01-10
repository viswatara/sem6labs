#include "mpi.h"
#include<stdio.h>
#include<string.h>
int main(int argc, char * argv[]){
	int rank,size;
	char *str;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Status status;
	if(rank==0){
		printf("Enter a value in master process");
		scanf("%s",str);
		MPI_Ssend(str,256,MPI_CHAR,1,1,MPI_COMM_WORLD);
		fprintf(stdout, "I have sent %s from process 0\n",str);
		MPI_Recv(str,256,MPI_CHAR,1,1,MPI_COMM_WORLD,&status);
		fprintf(stdout, "I have received %s from process 1\n",str);
	}
	else {
		MPI_Recv(str,256,MPI_CHAR,0,1,MPI_COMM_WORLD,&status);
		fprintf(stdout,"I have received %s in process 1\n",str);
		for(int i=0; i<strlen(str);i++){
			if(str[i]>='a'&& str[i]<='z'){
				str[i]=str[i]-32;
			}
			else if(str[i]>='A'&& str[i]<='Z'){
				str[i]=str[i]+32;
			}
		}
		MPI_Ssend(str,256,MPI_CHAR,0,1,MPI_COMM_WORLD);
		
		fflush(stdout);
	}
	
	MPI_Finalize();
	return 0;
}

