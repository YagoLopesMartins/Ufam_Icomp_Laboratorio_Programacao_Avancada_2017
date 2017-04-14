#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double troc=0, comp=0;
void selecao( int vetor[], int tamanhoVetor ){
   int i, j, posicaoValorMinimo;
   int controle,troca=0;
   int aux;  
   
   for (i = 0; i < ( tamanhoVetor - 1 ); ++i){
      controle=0;
      posicaoValorMinimo=i;
      aux=vetor[i];
      for (j = ( i + 1 ); j < tamanhoVetor; ++j){
      	 comp++;
         if( vetor[j] < aux){
           posicaoValorMinimo = j;
           aux=vetor[j];
           controle=1;
         }
       }
       if(controle){
       	troca++;
       	vetor[posicaoValorMinimo]=vetor[i];
       	vetor[i]=aux;
       	troc++;
       }
       
    }
    //printf("Troca = %d\n", troca);
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
		int vetor[100000];
		while(!feof(f)) 
		{	
		     // LER vetor DO ARQUIVO 
			for (i=0;i<100000;i++) {
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
selecao(vetor,cont);
fim = clock();
tempogasto = (((double) (fim - inicio)) / CLOCKS_PER_SEC);
 printf("\n********* SelectSort **********\n");  
 printf("Tempo Gasto             : %lf\n",tempogasto);                                                           
 printf("Numero de Comparacao    : %lf\n",comp);
 printf("Numero de troca         : %lf\n",troc);
	}// fim if arq
  system("pause"); 
}
/*
 float main(){
    srand (time(NULL));
 	int vetor[50000], vt[2];
 	int i,j,aux=0,cont=0;
 	for(i=0;i<50000;i++){
      		aux= rand();
 	 	 vetor[i]=aux;
 		  cont++;
   	 }	
clock_t inicio, fim;
double tempogasto;
inicio = clock();
selecao(vetor,cont);
fim = clock();
tempogasto = (((double) (fim - inicio)) / CLOCKS_PER_SEC);
printf("\n#############################################################################");
printf("Selecao :%lf\n",tempogasto);                                                           
printf("comparacao :%d\n",comp);  
printf("troca :%d\n",troc);     
  system("pause"); 
}	*/
