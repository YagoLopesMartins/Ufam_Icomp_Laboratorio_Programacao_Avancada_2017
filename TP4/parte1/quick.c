#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double comp=0, troca=0;
int quick( int vetorDesordenado[], int posicaoInicio, int posicaoFim )
{
   int x,i,j,auxiliar,k;
   x = vetorDesordenado[posicaoInicio];
   i = posicaoInicio - 1;
   j = posicaoFim + 1;
   
   for(k=0;k<posicaoFim;k++) 
   {   comp++;
      do { j--; } while( vetorDesordenado[j]>x );
      comp++;
      do { i++; } while( vetorDesordenado[i]<x );
      
      comp++;
      if (i<j) 
      {
         auxiliar = vetorDesordenado[i];
         vetorDesordenado[i] = vetorDesordenado[j];
         vetorDesordenado[j] = auxiliar;
         troca++;
      }
      else
      {
         return j;
      }
   }
  
}

void quickSort( int *vetorDesordenado, int posicaoInicio, int posicaoFim )
{
   int pivot;
   if (posicaoInicio < posicaoFim) 
   {
      pivot = quick( vetorDesordenado, posicaoInicio, posicaoFim);
      quickSort( vetorDesordenado, posicaoInicio, pivot);
      quickSort(vetorDesordenado, pivot+1, posicaoFim);
   }
}
float main(int argc, char *argv[]) {
	if (argc == 2) { // verifica o padrao de entrada	
		FILE *f;
		char *nome = argv[1]; // ponteiro para acesso do nome do arquivo
		f = fopen(nome,"r");
		if (f== NULL)
			exit(1);

		int i,j, cont = 0;
		srand (time(NULL));
		int vetor[50000];
		while(!feof(f)) 
		{	
		     // LER vetor DO ARQUIVO 
			for (i=0;i<50000;i++) {
				fscanf(f,"%d\t",&vetor[i]);
				cont++;
			}
		       // imprime vetor
			//for(i=0;i<1000;i++){
			//	printf("\t%d",vetor[i]);
			//}
		}// fim while do arquivo
clock_t inicio, fim;
double tempogasto;
inicio = clock();
quickSort(vetor,0,49999);
fim = clock();
tempogasto = (((double) (fim - inicio)) / CLOCKS_PER_SEC);
 printf("\n********* QuickSort **********\n");  
 printf("Tempo Gasto             : %lf\n",tempogasto);                                                           
 printf("Numero de Comparacao    : %lf\n",comp);
 printf("Numero de troca         : %lf\n",troca);
	}// fim if arq
  system("pause"); 
}
/*
float main(){	   
    srand (time(NULL));
 	int vetor[50000];
 	int i,j,aux=0,cont=0;
   for(i=0;i<50000;i++){
      aux= rand();
 	  vetor[i]=aux;
 	  cont++;
    }	

 //int vet[7]={2,5,6,3,4,7,1};
clock_t inicio, fim;
double tempogasto;
inicio = clock();
quickSort(vetor,0,50000);
fim = clock();
tempogasto = (((double) (fim - inicio)) / CLOCKS_PER_SEC);
printf("\n#############################################################################\n");
printf("QuickSort  :%lf\n",tempogasto);                                                           
printf("Trocas     :%lf\n",troca);
printf("Comparacao :%lf\n",comp);   
  system("pause"); 
}*/
