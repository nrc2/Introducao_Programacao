#include <stdio.h>
#include <string.h>

int main(){
    char plnd[10]={"ARARBJSA"};
    char aux[10]={0};
    int tam, i, j;

    tam = strlen(plnd);
    for(i=0, j=1; i<tam; i++, j++){
        aux[i] = plnd[tam-j];
    }
    if(strcmp(plnd,aux)==0){
        printf("E palindromo");
    }
    else{
        printf("E nao!");
    }


    return 0;
}