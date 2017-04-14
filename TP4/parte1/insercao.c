#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h> 
double troc=0, comp=0;
void insercao(int str[], int tamVet){
 int Temp,troca=0, compa=0; 
 int i,j;
 for( i=1 ;i<tamVet ;++i){
   Temp=str[i];
   compa++;
   comp++;
   for(j=i-1;j>=0 && Temp<str[j];j--){
   	str[j+1]=str[j];
   	troca++;
   	troc++;
   }
   str[j+1]=Temp;
  }
  //printf("===tr :%d\n",troca);
  //printf("Compara: %d \n", compa);
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
insercao(vetor,cont);
fim = clock();
tempogasto = (((double) (fim - inicio)) / CLOCKS_PER_SEC);
 printf("\n********* InsertSort **********\n");  
 printf("Tempo Gasto             : %lf\n",tempogasto);                                                           
 printf("Numero de Comparacao    : %lf\n",comp);
 printf("Numero de troca         : %lf\n",troc);
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
//for(i=0;i<5;i++){
//	printf("%d\n",vetor[i]);
//}
clock_t inicio, fim;
double tempogasto;
inicio = clock();
insercao(vetor,cont);
fim = clock();
tempogasto = (((double) (fim - inicio)) / CLOCKS_PER_SEC);
printf("\n#############################################################################");
printf("Insercao   :%lf\n",tempogasto);                                                           
printf("Troca      :%lf\n",troc);
printf("Comparacao :%lf\n", comp); 
  system("pause"); 
}*/
