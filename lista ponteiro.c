#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char c = 'a';
    char *pc;
    pc = &c;

    printf("QUESTAO 1\n\n");

    printf("a)\n");
    printf("O endereco de c e %p;\nO seu valor e: %c\n\n", &c, c);
    printf("b)\n");
    printf("O valor de pc e: %p\nO valor guardado no endereco apontado:%c\n\n", pc, *pc);
    printf("c)\n");
    printf("O endereco de pc: %p\n\n", &pc);
    printf("d)\n");
    printf("O endereco do valor guardado no endereco apontado por pc: %p\nO valor guardado no endereco de pc:%p\n\n", &*pc, *&pc);
    printf("e)\n");
    /* printf("O endereco do valor guardado, 'a', é o endereco de c e\n
    o endereco apontado por pc é o endereco de c, logo esse endereco de c\n
    será o valor guardado no endereco de pc\n
    por isso são os mesmos enderecos.\n\n"); */

    /*..........PROXIMA QUESTAO............ */

    printf("QUESTAO 2\n\n");
    int vet[5] = {1, 2, 3, 4, 5};
    int *p;
    p = &vet;

    printf("A)\n");
    /*  printf("O vet é um vetor, logo ele guarda valores nao um endereco\n
    Agora o endereco guardado por p é: %p\n\n", p); */

    printf("B)\n");
    printf("Os valores de vet sao: { ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d, ", p[i]);
    }
    printf("}\n\n");

    printf("C)\n");
    printf("Os valores de vet sao: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d, ", *(p + i));
    }
    printf("\n\n");

    printf("D)\n");
    printf("Os valores de vet sao: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d, ", vet[i]);
    }
    printf("\n\n");

    /*..........PROXIMA QUESTAO............ */

    printf("QUESTAO 3\n\n");

    char str[50] = {0};     // String
    char str_inv[50] = {0}; // String invertida
    char *ptr_str = str;
    char *ptr_inv = str_inv;
    int i = -1;

    scanf(" %s", str);

    i += 1;
    while (i < 50 && *(ptr_str + i) != '\0')
        i++;

    while (i > 0)
    {
        *(ptr_inv++) = *(ptr_str + i - 1);
        i--;
    }

    *ptr_inv = '\0';

    printf("A)\n");

    printf("A string e': %s\n", str);
    printf("O inverso da string : %s\n\n", str_inv);

    /* printf("B)\n");
    printf("a função scanf recebe o endereço de memória onde deve\n
    salvar o que foi lido, um vetor independente do tipo\n
    fica organizado na memoria de forma sequencial\n
    logo o nome da string é similar a um ponteiro\n
    para o início do vetor\n
    logo o scanf já sabe a primeira posicao\n
    e vai salvando o resto nas proximas \n\n"); */

    /*..........PROXIMA QUESTAO............ */

    // printf("QUESTAO 4\n\n");

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

    int main()
    {
        printf("QUESTAO 4\n\n");
        int j = 2, i = 0, k = 0;
        // Perceba de início que irei trabalhar com j sendo igual a '2';

        char sttr;
        char **vetor = (char **)malloc(1 * sizeof(char *));
        // Irei fazer a alocação primeiro dos dois ponteiros;
        if (vetor == NULL)
        {
            printf("Erro na alocacao!!!!!\n");
            free(vetor);
            exit(1);
        };
        vetor[0] = (char *)malloc(sizeof(char));
        if ((vetor + 0) == NULL)
        {
            printf("Erro na alocacao!!!!!\n");
            free(vetor);
            exit(1);
        }

        while (scanf("%c", &sttr) != EOF)
        {
            /* //Após escanear eu já faço uma realocação para ter
            mais espaço e depois guardar os valores */
            i++;
            if (sttr != '\n' && sttr != ' ')
            {
                vetor[j - 2] = (char *)realloc(vetor[j - 2], (i + 1) * sizeof(char));
                if ((vetor + i) == NULL)
                {
                    printf("Erro na alocacao!!!!!\n");
                    free(vetor);
                    exit(1);
                }
                vetor[j - 2][i - 1] = sttr;
                vetor[j - 2][i] = '\0';
            }

            else
            /*  Aqui é quando estou no fim da palavra
            e quero mais uma linha */
            {

                vetor = (char **)realloc(vetor, j * sizeof(char *));
                if (vetor == NULL)
                {
                    printf("Erro na alocacao!!!!!\n");
                    free(vetor);
                    exit(1);
                }
                vetor[j - 1] = (char *)malloc(sizeof(char));
                if ((vetor + (j - 1)) == NULL)
                {
                    printf("Erro na alocacao!!!!!\n");
                    free(vetor);
                    exit(1);
                }

                i = 0;
                j++;
            }
        }

        for (int l = 0; l < (j - 2); l++)
        {
            printf("%s\n", vetor[l]);
        }

        for (int indice = 0; indice < j; indice++)
        {
            free(vetor[indice]);
        }
        free(vetor);

        return 0;
    }

    /*..........PROXIMA QUESTAO............ */

    // printf("QUESTAO 5\n\n");

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

    struct el_lista
    {
        int valor;
        struct el_lista *proximo;
    };

    int main()
    {
        printf("QUESTAO 5\n\n");

        struct el_lista *loop = NULL;
        int i = 0, j = 1, num;

        while (scanf("%d", &num) && num)
        {
            loop = (struct el_lista *)realloc(loop, j * sizeof(struct el_lista));
            if (loop == NULL)
            {
                printf("Erro na alocacao!!!!!\n");
                free(loop);
                exit(1);
            }
            loop[i].valor = num;
            if (i > 0)
            {
                loop[i - 1].proximo = &loop[i];
            }
            loop[i].proximo = NULL;
            i++;
            j++;
        }

        while (loop != (struct el_lista *)0)
        {
            printf("\n%d\n", loop->valor);
            loop = loop->proximo;
        }

        free(loop);

        return 0;
    }
    return 0;
}