#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>     
  double troc=0 ; 
  double comp=0;

int metodoBolha(int *vetor, int tamanho){
        int aux, troca, i, j;
 
        troca=1; /*A vari�vel "troca" ser� a verifica��o da troca em cada passada*/
 
        for(j=tamanho-1; (j>=1)/* && (troca==1)*/; j--) 
        {
           // troca=0; /*Se o valor continuar 0 na pr�xima passada quer dizer que n�o houve troca e a fun��o � encerrada.*/
                for(i=0; i<j; i++)
                {         comp+=1;
                        if(vetor[i]>vetor[i+1]){
                                aux=vetor[i];
                                vetor[i]=vetor[i+1];
                                vetor[i+1]=aux;
                               // troca=1; /*Se houve troca, "troca" recebe 1 para continuar rodando.*/
                                troc+=1;
                       }
                }
         }
		// IMPRIME O VETOR ORDENADO
		//	printf("\n");
			//for(i=0;i<1000;i++){
			//	printf("\t%d",vetor[i]);
		//	}
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
metodoBolha(vetor,cont);
fim = clock();
tempogasto = (((double) (fim - inicio)) / CLOCKS_PER_SEC);
 printf("\n********* BublleSort **********\n");  
 printf("Tempo Gasto             : %lf\n",tempogasto);                                                           
 printf("Numero de Comparacao    : %lf\n",comp);
 printf("Numero de troca         : %lf\n",troc);
	}// fim if arq
  system("pause"); 
}
/*
float main(){	   
    srand (time(NULL));
  
 	int vetor[1000000];
 	int i,j,aux=0,cont=0,auxt=0;
 for(i=0;i<1000000;i++)
 {	
      aux= rand();
 	  vetor[i]=aux;
 	  cont++;
 }	
	//for(i=0;i<10000;i++){
	//	printf("\t%d",vetor[i]);
	//}

clock_t inicio, fim;
double tempogasto;
inicio = clock();
metodoBolha(vetor,cont);
fim = clock();
tempogasto = (((double) (fim - inicio)) / CLOCKS_PER_SEC);
printf("\n#############################################################################");
printf("\nBublleSort :%lf\n",tempogasto);                                                           
 printf("Compara��o: %lf\n",comp);
 printf("troca: %lf\n",troc);
         
  system("pause"); 
}	*/
