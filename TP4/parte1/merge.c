#include<stdio.h>
#include<stdlib.h>
#include<time.h>
double comp=0, troca=0;
int merge(int p,int q,int r,int v[]){
	int i,j,k,*w;
	// intercalacao no vetor temporario w	
	w=malloc((r-p)*sizeof(int));
	i=p;
	j=q;
	k=0;
	while(i<q && j<r){
		// j passou do final da primeira metade, pegar v[i]
		comp++;
		
		if(v[i]>=v[j]){
			w[k++]=v[i++];
			troca++;
		}
		else{
		 // i passou do final da primeira metade, pegar v[j]	
			w[k++]=v[j++];
		//	troca++;
		}
	}
	
	while(i<q){
		w[k++]=v[i++];
	//	troca++;
	}
	while(j<r){
		w[k++]=v[j++];
	}
	// copia vetor intercalado para o vetor original
	
	for(i=p;i<r;i++){
		v[i]=w[i-p];
	//	troca++;		
	}

	free(w);

}

int mergeSort(int p, int r, int v[]){
	if(p<r-1){
		int q=((p+r)/2);
		// ordenacao recursiva das duas metades
		mergeSort(p,q,v);
		mergeSort(q,r,v);
		merge(p, q ,r, v);
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
mergeSort(0, 50000,vetor);
fim = clock();
tempogasto = (((double) (fim - inicio)) / CLOCKS_PER_SEC);
 printf("\n********* MergeSort **********\n");  
 printf("Tempo Gasto             : %lf\n",tempogasto);                                                           
 printf("Numero de Comparacao    : %lf\n",comp);
 printf("Numero de troca         : %lf\n",troca);
	}// fim if arq
  system("pause"); 
}
/*
float main(){
    srand (time(NULL));
  
 	int vetor[2000000];
 	int i,j,aux=0,cont=0;
 	for(i=0;i<2000000;i++){
 	
      aux= rand();
 	  vetor[i]=aux;
 	  cont++;
    }	
//int vetor[7]={2,5,6,3,4,7,1};
clock_t inicio, fim;
double tempogasto;
inicio = clock();
aux=mergeSort(0, 2000000,vetor );
fim = clock();
tempogasto = (((double) (fim - inicio)) / CLOCKS_PER_SEC);
printf("\n#############################################################################");
printf("MergeSort   :%lf\n",tempogasto);                                                           
printf("Comparacoes :%lf\n",comp);
printf("Trocas      :%lf\n",troca); 
//for(i=0;i<5000;i++){
//	printf("\t%d",vetor[i]);
//}  
  system("pause"); 
}*/
