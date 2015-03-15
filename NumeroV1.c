#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <math.h>
#include <sys/time.h>
#include "mpi.h"

#define TAMANNO 100
#define EXP 100

int main (int argc, char ** argv)
{
    int i,n,o;
    int iId ; 
	int iNumProcs; 
    float almacen_num[TAMANNO];
	float resultado[TAMANNO]; 
	float frec[TAMANNO];
	float media = 0.0;
	float desviacionMedia = 0.0;
	double tmpInit = 0.0;
	double tmpFin = 0.0;
	float suma = 0.0f;
    MPI_Status status;
	

	MPI_Init (&argc ,&argv); 						
	MPI_Comm_rank(MPI_COMM_WORLD,&iId ); 			
	MPI_Comm_size(MPI_COMM_WORLD, &iNumProcs ); 	

    srand(time(NULL));
	
	tmpInit=MPI_Wtime(); 
	
	// El id=0 espera los resultados
	for(i=0;i<TAMANNO;i++)
        {
            resultado[i]=0; 
			frec[i]=0;
        }
        
	tmpInit = MPI_Wtime();
    if (iId!=0)
    {
		for(i=0;i<TAMANNO;i++)
        {
            almacen_num[i]=0; 
        }
          for(i=0;i<EXP;i++)
        {
            n = rand() % 100;
            almacen_num[n]++; 
        }
		 for(i=0;i<TAMANNO;i++)
        {
            printf("pid %d=> posicion array %d => %f\n",iId,i,almacen_num[i]); 
        }
		MPI_Send(almacen_num, TAMANNO, MPI_INT, 0, 0, MPI_COMM_WORLD);
	
    }
   	tmpFin = MPI_Wtime();
    if(iId == 0) 
    {
	int a;
		for(a = 0 ; a < iNumProcs ; a++)
		{
			if(a != 0){
				MPI_Recv(almacen_num, TAMANNO, MPI_INT, a, 0, MPI_COMM_WORLD, &status);
				for(o = 0; o < TAMANNO; o++)
				{
					resultado[o] += almacen_num[o]; 
				}			
			}
			
		}
		for(i=0;i<TAMANNO;i++)
		        {
		            printf("pid %d=> resultado array %d => %f\n",iId,i,almacen_num[i]); 
		        }

	//calculamos la media
	for(i = 0; i<TAMANNO;i++)
	{
		media+=(resultado[i]*i);
	}
	media=media/(EXP*(iNumProcs-1));
	printf("la media es: %f\n",media);
	//calculamos desviacion media

	for(i=0;i<TAMANNO;i++){
		desviacionMedia = abs(i-media)*resultado[i];
		
	}
	//calculamos lista de frecuencias
	for(i=0;i<TAMANNO;i++){
		frec[i] = (resultado[i]/EXP);
	}
	desviacionMedia/=(EXP*(iNumProcs-1));
	printf("PRUEBA GENERADOR NUMEROS ALEATORIOS:\n");
	printf("Semilla: %d\n",iId);
	printf("Numero de experimentos (%d): %d\n",iNumProcs,EXP);
	for(i=0; i<TAMANNO; i++)
	{
		//printf("%f\n",frec[i]);
		suma += frec[i];
	}
	printf("Tiempo: %f\n", tmpFin-tmpInit);
	printf("numProcs1: %f\n",suma);
    }
	
    MPI_Finalize();
	
    return 0;
}

/*
para el padre hay que hacer que genere la combinacion ganadora
	for(i=0;i<5;i++)
        {
            if(i >=2)
// SOLO HAY QUE GENERAR LOS NUMEROS QUE QUEDAN PARA EL BOLETO GANADOR
            {
				n = rand() % 50 + 1;
            }
            else
        	{
        		n = rand() % 50 + 1;
				o = rand() % 11 + 1;
        	}
//HAY QUE GENERAR A PARTE DEL EL NUMERO PARA EL BOLETO GANADOR, TAMBIEN LOS 2 NUMEROS ESPECIALES            

        }
        ademas debe generar un numero de boletos aleatorios entre 1 y 100
        nBoletos =  rand % 100+1;
//Algoritmo de distribucion de boletos.
Si el padre recibe que hay algun proceso que ya ha acabado con toda su cola de acciones
entonces cogera una tarea de la cola de aque proceso que este tardando mas en realizar
las tareas que tiene en su cola.
¿Como hacemos eso?
//Funcion para generar numeros random(con semilla No de proceso)
if((n=((rand() % 50) * nProc)) > 50)
	n /=2;
*/
