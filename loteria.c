#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define numeros 7
#define boletos 1000
#define categorias_ganadoras 13

void generar_combinacion_ganadora(int * );
void generar_boletos(int *,int *);
int comprobar_boleto(int*,int *);
void escrutinio(int *);

int main (int argc, char ** argv)
{
    int c_ganadora[numeros];    
    int c_dinero[categorias_ganadoras];

    int i;
    generar_combinacion_ganadora(c_ganadora);
    
    for(i=0;i<numeros;i++)
        printf("%i -",c_ganadora[i]);

    printf("\n");

    return 0;
}

void generar_combinacion_ganadora(int * c_ganadora ){
    int i,j,aleatorio;
    int esta=0;
    srand(time(NULL));
    for(i=0;i<numeros-2;i++)
    {
        aleatorio=rand()%50+1;
        for(j=0;j<i;j++)  if(c_ganadora[j]==aleatorio)esta=1;

        if(esta==1) i--;
        else c_ganadora[i] = aleatorio;

        esta=0;

    }        
    for(i=numeros-2;i<numeros;i++)
    {
        aleatorio=rand()%11+1;
        for(j=numeros-2;j<i;j++)  if(c_ganadora[j]==aleatorio)esta=1;

        if(esta==1) i--;
        else c_ganadora[i] = aleatorio;

        esta=0;

    }  
}

void generar_boletos(int *c_ganadora,int * aciertos){
    int i,j;
    int categoria;
	int aleatorio;
	int esta;
    int n_boleto[numeros];

    for(i=0;i<boletos;i++)
    {
        srand(time(NULL));
        for(i=0;i<numeros-2;i++)
        {
            aleatorio=rand()%50+1;
            for(j=0;j<i;j++)  if(n_boleto[j]==aleatorio)esta=1;

            if(esta==1) i--;    
            else n_boleto[i] = aleatorio;

            esta=0;

        }        
        for(i=numeros-2;i<numeros;i++)
        {
            aleatorio=rand()%11+1;
           for(j=numeros-2;j<i;j++)  if(n_boleto[j]==aleatorio)esta=1;

           if(esta==1) i--;
           else n_boleto[i] = aleatorio;
    
           esta=0;
        }  
        categoria=comprobar_boleto(c_ganadora,n_boleto);
    
        if(categoria==1)aciertos[categoria-1]++;
        else if(categoria==2)aciertos[categoria-1]++;
        else if(categoria==3)aciertos[categoria-1]++;
        else if(categoria==4)aciertos[categoria-1]++;
        else if(categoria==5)aciertos[categoria-1]++;
        else if(categoria==6)aciertos[categoria-1]++;
        else if(categoria==7)aciertos[categoria-1]++;
        else if(categoria==8)aciertos[categoria-1]++;
        else if(categoria==9)aciertos[categoria-1]++;
        else if(categoria==10)aciertos[categoria-1]++;
        else if(categoria==11)aciertos[categoria-1]++;
        else if(categoria==12)aciertos[categoria-1]++;
        else if(categoria==13)aciertos[categoria-1]++;
        else if(categoria==14)aciertos[categoria-1]++;
        else if(categoria==15)aciertos[categoria-1]++;
        else if(categoria==16)aciertos[categoria-1]++;
        else if(categoria==17)aciertos[categoria-1]++;
        else if(categoria==18)aciertos[categoria-1]++;
        
    }
}

int comprobar_boleto(int* c_ganadora,int * n_boleto)
{
    int nums,estrellas;
    int i,j;
    nums=estrellas=0;
    for(i=0;i<numeros-2;i++)
    {
        for(j=0;j<numeros-2;j++)
        {
            if(c_ganadora[i]==n_boleto[i]) nums++;         
        }          
    }
    for(i=numeros-2;i<numeros;i++)
    {
        for(j=numeros-2;j<numeros;j++)
        { 
             if(c_ganadora[i]==n_boleto[i])estrellas;         
        }
    }
    
    if(nums==5 && estrellas==2) return 1;
    else if(nums==5 && estrellas==1) return 2;
    else if(nums==5 && estrellas==0) return 3;
    else if(nums==4 && estrellas==2) return 4;
    else if(nums==4 && estrellas==1) return 5;
    else if(nums==4 && estrellas==0) return 6;
    else if(nums==3 && estrellas==2) return 7;
    else if(nums==2 && estrellas==2) return 8;
    else if(nums==3 && estrellas==1) return 9;
    else if(nums==3 && estrellas==0) return 10;
    else if(nums==1 && estrellas==2) return 11;
    else if(nums==2 && estrellas==1) return 12;
    else if(nums==2 && estrellas==0) return 13;
    else if(nums==1 && estrellas==1) return 14;
    else if(nums==0 && estrellas==2) return 15;
    else if(nums==1 && estrellas==0) return 16;
    else if(nums==0 && estrellas==1) return 17;
    else if(nums==0 && estrellas==0) return 18;
    
return 0;
}

void escrutinio(int *c_dinero){
	double recaudacion;
	recaudacion = boletos * 2;
	
	c_dinero[0]=recaudacion*0.5;
	c_dinero[1]=recaudacion*0.32;
	c_dinero[2]=recaudacion*0.048;
	c_dinero[3]=recaudacion*0.016;
	c_dinero[4]=recaudacion*0.008;
	c_dinero[5]=recaudacion*0.007;
	c_dinero[6]=recaudacion*0.007;
	c_dinero[7]=recaudacion*0.005;
	c_dinero[8]=recaudacion*0.023;
	c_dinero[9]=recaudacion*0.022;
	c_dinero[10]=recaudacion*0.037;
	c_dinero[11]=recaudacion*0.065;
	c_dinero[12]=recaudacion*0.176;
	c_dinero[13]=recaudacion*0.18;
	c_dinero[14]=recaudacion*0.086;
}
