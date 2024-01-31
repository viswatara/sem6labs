#include <stdio.h>
#include"mpi.h"

void Error_Handler(int error) {
  if (error != MPI_SUCCESS) {
    char s[256];
    int len, classe;
    MPI_Error_class(error, &classe);
    MPI_Error_string(error,s, & len);
    printf("[ERROR %d] : %s\n", classe, s);
  }
}

int main(int argc, char*argv[]){
	int rank,size,fact=1;
	int factsum,i;
	int error;
	MPI_Init(&argc,&argv);
	MPI_Errhandler_set(MPI_COMM_WORLD,MPI_ERRORS_RETURN);
	error=MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	Error_Handler(error);
	error=MPI_Comm_size(MPI_COMM_WORLD,&size);
	Error_Handler(error);
	for(i=1;i<=rank+1;i++){
		fact=fact*i;
	}

	error=MPI_Scan(&fact,&factsum,1,MPI_INT,MPI_SUM,MPI_COMM_WORLD);
	Error_Handler(error);
	if(rank==size-1){
		printf("Sum of all factorial= %d",factsum);
	}
	MPI_Finalize();
	return 0;
}
