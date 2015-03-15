#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mpi.h"
#define TAMANNO 100

int main (int argc, char ** argv)
{
    int i,n;
    int iId ; 
	int iNumProcs; 
    int almacen_num[TAMANNO];

    double tmpInic = 0.0; 
	double tmpFin; 

    MPI_Status status;
	

	MPI_Init (&argc ,&argv); 						
	MPI_Comm_rank(MPI_COMM_WORLD,&iId ); 			
	MPI_Comm_size(MPI_COMM_WORLD, & iNumProcs ); 	

    srand(time(NULL));
	
	tmpInic=MPI_Wtime(); 
	
	// El id=0 espera los resultados
	
        for(i=0;i<TAMANNO;i++)
        {
            almacen_num[i]=0; 
        }
      
    if (iId!=0)
    {
          for(i=0;i<1000;i++)
        {

            n = rand() % 100;
            almacen_num[n]++; 
        }
        printf("_______________Hijo(%i)______________\n",iId);
        for(i=0;i<TAMANNO;i++)
        {
            printf("%i: %i\n",i,almacen_num[i]);
        }
        MPI_Bcast(almacen_num,TAMANNO,MPI_INT,0,MPI_COMM_WORLD);	
    }
   
    if(iId == 0) 
    {
        MPI_Reduce(almacen_num,almacen_num,TAMANNO,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
         for(i=0;i<TAMANNO;i++)
        {
            printf("- %i: %i\n",i,almacen_num[i]);
        } 
    }
    MPI_Finalize();

    return 0;
}


