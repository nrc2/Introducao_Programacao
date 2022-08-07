#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **carregaRegulagensDeFilial(int filial, int *tamVet){
    FILE *pArq = NULL;
    char **m = NULL;
    char filialS[20] = "";
    char *linhas = NULL;
    char regulagem[10] = "Pablo";
    char *p = NULL;
    int i;

    for(i = 101; i <= filial; i++){

        itoa(i, filialS, 10);

        strcat(filialS, ".txt");

        printf("%s\n", filialS);


        pArq = fopen(filialS, "rt");
            if(pArq == NULL){
                printf("Erro ao abrir arq\n");
                exit(-1);
            }
        
        linhas = (char *) malloc(256 * sizeof(char));
            if( linhas == NULL){
                printf("Erro ao alocar\n");
                exit(-2);
            }
        
        while(fscanf(pArq, " %[^\n]", linhas) != EOF){
            
            strcpy(regulagem, "");

            p = memchr(linhas, '[', strlen(linhas));

            printf("%s\n", p);

            strncpy(regulagem, p, 9);

            regulagem[9] = '\0';

            (*tamVet)++;

            if((*tamVet) == 1){
                m = (char **) malloc(sizeof(char *));
            }
            else{
                m = (char **) realloc(m, (*tamVet) * sizeof(char *));
            }

            if(m == NULL){
                printf("Erro ao alocar");
                exit(-1);
            }

            m[(*tamVet) - 1] = malloc(10 * sizeof(char));

            if(m[(*tamVet) - 1] == NULL){
                printf("Erro ao alocar");
                exit(-1);
            }

            strcpy(m[(*tamVet) - 1], regulagem);

        }

        free(p);
        free(linhas);
        fclose(pArq);


    }

    return m;

}

int main(){
    int filial, tam = 0, i;
    char **matrizRegulagens = NULL;

    do{
        printf("Entre com o numero da ultima filial: |101 <= F <= 199|\n");
        scanf("%d", &filial);
    }while((filial < 101) || (filial > 199));


    matrizRegulagens = carregaRegulagensDeFilial(filial, &tam);

    for(i = 0; i < tam; i++){
        printf("%s\n", matrizRegulagens[i]);
    }

    for(i = 0; i < tam; i++){
        free(matrizRegulagens[i]);
    }

    free(matrizRegulagens);


    return 0;
}