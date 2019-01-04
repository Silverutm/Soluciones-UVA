#include <mpi.h>
#include <stdio.h>
#include <string.h>
const int max_string = 100;
int main()
{
	char greeting[max_string];
	int comm_sz;
	int my_rank;
	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

	if (my_rank)
	{
		sprintf(greeting, "saludos del proceso %d de %d\n", 
			my_rank, comm_sz);
		MPI_Send(greeting, strlen(greeting)+1, MPI_CHAR, 0, 0,
			MPI_COMM_WORLD);
	}
	else
	{
		printf("saludos del proceso %d de %d\n", 
			my_rank, comm_sz);
		for (int q = 1; q < comm_sz; ++q)
		{
			MPI_Recv( greeting, max_string, MPI_CHAR,q, 0,
				MPI_COMM_WORLD, MPI_STATUS_IGNORE );
			printf("%s\n",greeting );
		}
	}
	MPI_Finalize();
	return 0;
}