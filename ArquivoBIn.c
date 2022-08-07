#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int num, qtd = 0;
    int *Pnum = NULL;
    int *pLidas = NULL;
    int qtdLidas = 0;
    int *aux = Pnum;
    int numLidas;

    printf("Escreva um numero:\n");

    while (scanf("%d", &num) && num != 0)
    {
        printf("Escreva um numero:\n");
        Pnum = (int *)realloc(Pnum, (qtd + 1) * sizeof(int));
        if (Pnum == NULL)
        {
            printf("Erro na alocacao!!");
            free(aux);
            exit(1);
        }
        Pnum[qtd] = num;
        qtd++;
    }

    FILE *arq = fopen("listaNum.bin", "a+");
    if (arq == NULL)
    {
        printf("Deu ruim\n");
        exit(1);
    }
    fwrite(Pnum, sizeof(int), qtd, arq);
    /*  fclose(arq);
  FILE *arq = fopen("listaNum.bin", "r");
  if (arq == NULL)
  {
      printf("Deu ruim\n");
      exit(1);
  } */
    rewind(arq);
    while (fread(&numLidas, sizeof(int), 1, arq) != 0)
    {

        pLidas = (int *)realloc(pLidas, (qtdLidas + 1) * sizeof(int));
        if (pLidas == NULL)
        {
            printf("Erro na alocacao!!");
            exit(1);
        }
        pLidas[qtdLidas] = numLidas;
        qtdLidas++;
    }

    for (int j = 0; j < qtdLidas; j++)
    {
        printf("%d\n", pLidas[j]);
    }
    fclose(arq);

    return 0;
}