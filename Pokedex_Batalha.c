#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char nome[30];
    int ataque, defesa;
} Pokemon;

typedef struct
{
    char nome[30];
    Pokemon *pokebola;
    int nPokemons, pontuacao;
} Treinador;

Treinador *addTreinador(Treinador *treinadores, int *qtdCompetidores);
Treinador *addPokemon(Treinador *treinadores, char *nomeTreinador, Pokemon pokemon, int qtdCompetidores);
Treinador *removeTreinador(Treinador *treinadores, int *qtdCompetidores, int indexTreinador);
char *batalha(Treinador **treinadores, char *nomeCompetidor1, char *nomeCompetidor2, int indexPokemon1, int indexPokemon2, int *qtdCompetidores);
void Menu();

int main()
{
    Menu();

    return 0;
}

void Menu()
{
    int qtdCompetidores = 0, opcao;
    Treinador *lista = NULL;
    Treinador *listaArq;
    char *vencedor;
    int i, j, size;
    char nomeAux[30];
    char competidor1[30], competidor2[30];
    int pokemon1, pokemon2;
    Pokemon novo;
    /* FILE *arq;
    arq = fopen("Planilha.bin", "a+b");
    if (arq == NULL)
    {
        printf("arquivo not found");
        exit(-1);
    }
    fwrite("Planilha de Batalhas Pokemnons\n", sizeof(char), 32, arq);
 */
    do
    {
        printf("\t[MENU]\n");
        printf("Escolha sua opcao:\n");
        printf("[1] Adicionar Competidor\n");
        printf("[2] Adicionar Pokemon\n");
        printf("[3] Batalhar\n");
        printf("[0] Sair do Programa\n");
        scanf("%d", &opcao);

        switch (opcao)
        {

        case 1:
            lista = addTreinador(lista, &qtdCompetidores);
            //fwrite(lista, sizeof(Treinador), 1, arq);
            
            /* Treinador aux;
            
            fseek(arq, 0, SEEK_END);
            size = ftell(arq);
            size = size / sizeof(Treinador);
            rewind(arq);
            Treinador *PLidas = (Treinador*) malloc(size * sizeof(Treinador));
            int i = 0;

            while(fread(&aux, sizeof(Treinador), size, arq)){
                PLidas[i] = aux;
                i++;
            } */

            for (i = 0; i < qtdCompetidores; i++)
            {
                printf("%d.\n", (i + 1));
                printf("Nome: %s\n", lista[i].nome);
                printf("Pontuacao: %d\n", lista[i].pontuacao);
                printf("Numero de pokemons capturados:%d\n", lista[i].nPokemons);
                if (lista[i].nPokemons > 0)
                {
                    for (j = 0; j < lista[i].nPokemons; j++)
                    {
                        printf("Pokemon %d: %s\n", j, lista[i].pokebola[j].nome);
                        printf("Ataque: %d\n", lista[i].pokebola[j].ataque);
                        printf("Defesa: %d\n", lista[i].pokebola[j].defesa);
                    }
                }
            }
            break;
        case 2:
            printf("Qual o nome do treinador que o capturou:\n");
            scanf(" %29[^\n]", nomeAux);
            printf("Entre com os dados do Pokemon:\n");
            printf("Nome:\n");
            scanf(" %s", novo.nome);
            printf("Ataque: ");
            scanf("%d", &novo.ataque);
            printf("Desfesa: ");
            scanf("%d", &novo.defesa);

            lista = addPokemon(lista, nomeAux, novo, qtdCompetidores);
            //fwrite(lista, sizeof(Treinador), 1, arq);

            break;

        case 3:
            printf("\t---BATALHA---\n");
            printf("Entre com os dados da batalha\n");
            printf("Nome do primeiro competidor:\n>>");
            scanf(" %29[^\n]", competidor1);
            printf("Qual o indice do pokemon de %s que vai lutar?\n>>", competidor1);
            scanf("%d", &pokemon1);
            printf("Nome do segundoo competidor:\n>>");
            scanf(" %29[^\n]", competidor2);
            printf("Qual o indice do pokemon de %s que vai lutar?\n>>", competidor2);
            scanf("%d", &pokemon2); 
            vencedor = batalha(&lista, competidor1, competidor2, pokemon1, pokemon2, &qtdCompetidores);

            printf("\ttO VENCEDOR É %s\n", vencedor);
            break;

        default:
            break;
        }
    } while (opcao != 0);

    for (i = 0; i < qtdCompetidores; i++)
    {
        free(lista[i].pokebola);
    }
    free(lista);
    //fclose(arq);
}
Treinador *addTreinador(Treinador *treinadores, int *qtdCompetidores)
{
    Treinador aux;
    Treinador *p = treinadores;
    aux.pontuacao = 0;
    aux.nPokemons = 0;

    printf("Entre com o nome do novo treinador\n");
    scanf(" %29[^\n]", aux.nome);

    p = (Treinador *) realloc(p, ((*qtdCompetidores) + 1) * sizeof(Treinador));
    if (p == NULL)
    {
        printf("Sem memoria\n");
        exit(-1);
    }

    treinadores = p;

    treinadores[(*qtdCompetidores)] = aux;
    // vetor[i] = 0;

    (*qtdCompetidores)++;

    return treinadores;
}

Treinador *addPokemon(Treinador *treinadores, char *nomeTreinador, Pokemon pokemon, int qtdCompetidores)
{
    Treinador *p = treinadores;
    int i, flag = 0;
    Treinador *pAux = p;

    for (i = 0; (i < qtdCompetidores) && (flag == 0); i++)
    {
        if (strcmp(nomeTreinador, p[i].nome) == 0)
        {

            if (p[i].nPokemons == 0)
            {

                p[i].pokebola = (Pokemon *)malloc((p[i].nPokemons + 1) * sizeof(Pokemon));
                if (p[i].pokebola == NULL)
                {
                    printf("Erro ao alocar\n");
                    exit(-2);
                }
            }
            else
            {
                p[i].pokebola = (Pokemon *)realloc(p[i].pokebola, (p[i].nPokemons + 1) * sizeof(Pokemon));
                if (p[i].pokebola == NULL)
                {
                    printf("Erro ao alocar\n");
                    free(pAux);
                    exit(-2);
                }
            }

            p[i].pokebola[p[i].nPokemons] = pokemon;

            p[i].nPokemons++;

            flag = 1;
        }
    }
    return p;
}
Treinador *removeTreinador(Treinador *treinadores, int *qtdCompetidores, int indexTreinador)
{

    Treinador *p = treinadores;
    Treinador aux;
    int i, flag = 1;

    for (i = 0; (i < (*qtdCompetidores)) && (flag); i++)
    {

        if (i == indexTreinador)
        {

            p[i] = p[(*qtdCompetidores) - 1];

            p = (Treinador *)realloc(p, ((*qtdCompetidores) - 1) * sizeof(Treinador));
            if (p == NULL)
            {
                printf("Sem memoria\n");
                free(treinadores);
                exit(-3);
            }

            (*qtdCompetidores)--;

            flag = 0;
        }
    }

    return p;
}

char *batalha(Treinador **treinadores, char *nomeCompetidor1, char *nomeCompetidor2, int indexPokemon1, int indexPokemon2, int *qtdCompetidores)
{
    char *vencedor = NULL;
    int i, j;
    Pokemon poke1, poke2;

    for (i = 0; i < (*qtdCompetidores); i++)
    {
        if (strcmp(nomeCompetidor1, (*treinadores)[i].nome) == 0)
        {
            for (j = 0; j < (*treinadores)[i].nPokemons; j++)
            {
                if (j == indexPokemon1)
                {
                    poke1 = (*treinadores)[i].pokebola[j];
                }
            }
        }
        else if (strcmp(nomeCompetidor2, (*treinadores)[i].nome) == 0)
        {
            for (j = 0; j < (*treinadores)[i].nPokemons; j++)
            {
                if (j == indexPokemon2)
                {
                    poke2 = (*treinadores)[i].pokebola[j];
                }
            }
        }
    }

    if ((poke1.ataque - poke2.defesa) > (poke2.ataque - poke1.defesa))
    {
        vencedor = nomeCompetidor1;

        for (i = 0; i < (*qtdCompetidores); i++)
        {
            if (strcmp(nomeCompetidor1, (*treinadores)[i].nome) == 0)
            {
                (*treinadores)[i].pontuacao++;
            }
            else if (strcmp(nomeCompetidor2, (*treinadores)[i].nome) == 0)
            {
                (*treinadores)[i].pontuacao--;
                if ((*treinadores)[i].pontuacao == -1)
                {
                    (*treinadores) = removeTreinador((*treinadores), qtdCompetidores, i);
                }
            }
        }
    }
    else
    {
        vencedor = nomeCompetidor2;
        for (i = 0; i < (*qtdCompetidores); i++)
        {
            if (strcmp(nomeCompetidor1, (*treinadores)[i].nome) == 0)
            {
                (*treinadores)[i].pontuacao--;
                if ((*treinadores)[i].pontuacao == -1)
                {
                    (*treinadores) = removeTreinador((*treinadores), qtdCompetidores, i);
                }
            }
            else if (strcmp(nomeCompetidor2, (*treinadores)[i].nome) == 0)
            {
                (*treinadores)[i].pontuacao++;
            }
        }
    }

    return vencedor;
}
