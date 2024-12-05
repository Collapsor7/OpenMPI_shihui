#include <omp.h>

int main(int argc, char *argv[])
{
	printf("Masterthread started\n");
 
    #pragma omp parallel if(false)        // disable paralled
	{
		printf("hello,OpenMP, serial code\n");
	}// End of parallel region
 
 
    #pragma omp parallel           // decided bydefault implementation
	{
		printf("hello,OpenMP, paralled code 1\n");
	}// End of parallel region
 
	omp_set_num_threads(2);
    #pragma omp parallel if(true) //decided by omp_set_num_threads
	{
		printf("hello,OpenMP, paralled code 2\n");
	}// End of parallel region
 
    #pragma omp parallel if(true) num_threads(3) // decided by num_threads
	{
		printf("hello,OpenMP, paralled code 3\n");
	}// End of parallel region
 
	printf("Masterthread finished\n");
 
	return(0);
}
