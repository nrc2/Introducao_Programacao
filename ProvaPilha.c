#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float pReal;
    float pImg;
} Complexo;

void empilhe(Complexo **cPilha, Complexo umC, int *tPilha);
Complexo desempilhe(Complexo **cPilha, int *tPilha);
Complexo topo(Complexo *cPilha, int tPilha);
int pilhaVazia(Complexo *cPilha, int tPilha);
void salvePilha(Complexo *cPilha, int tPilha);
Complexo *recuperePilha(int *tPilha);

int main()
{

    Complexo *listaP = NULL;
    Complexo complexo;
    Complexo desemp;
    Complexo top;
    Complexo *recup;
    int estado;
    int tamP = 0, op;
    int i, j;

    do
    {
        printf("\t===MENU OPCOES===\n");
        printf("[1] Empilhar um Complexo\n");
        printf("[2] Desempilhar\n");
        printf("[3] Qual o Topo da Pilha\n");
        printf("[4] Estado da pilha\n");
        printf("[5] Salve a Pilha em um Arquivo\n");
        printf("[6] O que esta em arquivo");
        printf("[0] Sair\n");

        scanf("%d", &op);
        switch (op)
        {

        case 1:

            printf("Digite o numero real da Pilha:\n");
            scanf("%f", &complexo.pReal);
            printf("Digite o numero imaginario da Pilha:\n");
            scanf("%f", &complexo.pImg);

            empilhe(&listaP, complexo, &tamP);

            for (i = 0; i < tamP; i++)
            {
                printf("Pilha[%d]\nNum Real: %f\nNum Imag:%f\n", (i + 1), listaP[i].pReal, listaP[i].pImg);
            }
            break;

        case 2:
            desemp = desempilhe(&listaP, &tamP);
            printf("Numero do topo removido com sucesso!!\n\n");
            break;
        case 3:
            top = topo(listaP, tamP);
            printf("O numero do topo e:%f e %f\n\n", top.pReal, top.pImg);
            break;
        case 4:
            estado = pilhaVazia(listaP, tamP);
            printf("O returno foi: %d\n", estado);
            break;
        case 5:
            salvePilha(listaP, tamP);
        case 6:
            recup = recuperePilha(&tamP);
            

            break;

            break;
        default:
            break;
        }
    } while (op != 0);
    free(listaP);
    return 0;
}
void empilhe(Complexo **cPilha, Complexo umC, int *tPilha)
{

    Complexo *aux;

    aux = (Complexo *)realloc((*cPilha), ((*tPilha) + 1) * sizeof(Complexo));

    if (aux == NULL)
    {
        printf("Erro na alocacao!");
        free((*cPilha));
        exit(1);
    }
    (*cPilha) = aux;
    (*cPilha)[(*tPilha)] = umC; // A ÚLTIMA POSIÇÃO É O TOPO

    (*tPilha)++;
}
Complexo desempilhe(Complexo **cPilha, int *tPilha)
{
    Complexo *p = *cPilha;
    Complexo aux;
    int i = ((*tPilha) - 1);

    aux = p[i];
    p = (Complexo *)realloc(p, (*tPilha) * sizeof(Complexo));
    if (p == NULL)
    {
        printf("Sem memoria\n");
        free(cPilha);
        exit(-3);
    }

    (*tPilha)--;

    return (aux);
}
Complexo topo(Complexo *cPilha, int tPilha)
{
    Complexo aux = cPilha[tPilha - 1];
    return aux;
}
int pilhaVazia(Complexo *cPilha, int tPilha)
{
    if ((cPilha == NULL) || (tPilha == 0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void salvePilha(Complexo *cPilha, int tPilha)
{
    FILE *arq = fopen("Complexos.bin", "wb");

    if (arq == NULL)
    {
        printf("Deu ruim\n");
        free(cPilha);
        exit(1);
    }
    fwrite(cPilha, tPilha, sizeof(Complexo), arq);
    fclose(arq);
}
Complexo *recuperePilha(int *tPilha)
{
    FILE *arq = fopen("Complexo.bin", "rb");
    Complexo *complexos = NULL;
    Complexo aux;
    int i = 0;
    if (arq == NULL)
    {
        printf("Erro ao abrir o arq\n");
        exit(-1);
    }

    while (fread(&aux, sizeof(Complexo), (*tPilha), arq) != 0)
    {
        complexos = (Complexo *)realloc(complexos, (*tPilha + 1) * sizeof(Complexo));
        if (complexos == NULL)
        {
            printf("Erro ao alocar\n");
            exit(-1);
        }
        complexos[i] = aux;
        i++;
    }

    fclose(arq);
    return complexos;
}
