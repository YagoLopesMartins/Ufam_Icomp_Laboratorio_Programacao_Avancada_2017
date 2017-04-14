#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *arq;
    arq = fopen("100000a.txt","w");

    int i, valor_aleatorio;
    for(i=0;i<100000;i++){
        valor_aleatorio = rand() % 100000;
        fprintf(arq,"%d\t",valor_aleatorio);
    }
    fclose(arq);
}




