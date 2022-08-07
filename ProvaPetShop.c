#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct teste{
    int id_pet, id_cliente;
    char nome_pet[100];
    char raca_pet[100];
    double altura, peso;
    int idade;
}Pet;


typedef struct{
    int id;
    int qtd_pets;
    char nome[100];
    char endereco[200];
    Pet *pets;
}Clientes;

void ordenaPets(Pet **p, int *qt_pets){
    int i, j;
    Pet aux;

    for(i = 0; i < (*qt_pets); i++){
        for(j = i + 1; j < (*qt_pets); j++){
            if((*p)[i].id_pet > (*p)[j].id_pet){
                aux = (*p)[j];
                (*p)[j] = (*p)[i];
                (*p)[i] = aux;
            }
        }
    }

}

Pet *leituraPets(int *qt_pets){
    FILE *p = NULL;
    Pet *aux = NULL;
    Pet temp;

    p = fopen("pets.bin", "rb");
        if(p == NULL){
            printf("Erro ao abrir o arq\n");
            exit(-1);
        }
    
    while(fread(&temp, sizeof(Pet), 1, p) != 0){
        
        aux = (Pet *) realloc(aux, (*qt_pets + 1) * sizeof(Pet));
            if( aux == NULL){
                printf("Erro ao alocar\n");
                exit(1);
            }
        
        aux[(*qt_pets)] = temp;

        (*qt_pets)++;
    }
    

    fclose(p);
    ordenaPets(&aux, qt_pets);
    return aux;

}

void ordenaClientes(Clientes **p, int *qt_clientes){
    int i, j;
    Clientes aux;

    for(i = 0; i < (*qt_clientes); i++){
        for(j = i + 1; j < (*qt_clientes); j++){
            if((*p)[i].id > (*p)[j].id){
                aux = (*p)[j];
                (*p)[j] = (*p)[i];
                (*p)[i] = aux;
            }
        }
    }

}

Clientes *leituraClientes(int *qt_clientes){
    FILE *p = NULL;
    Clientes *aux = NULL;
    Clientes temp;

    p = fopen("clientes.bin", "rb");
        if(p == NULL){
            printf("Erro ao abrir o arq\n");
            exit(-1);
        }
    
    while(fread(&temp, sizeof(Clientes), 1, p) != 0){
        
        aux = (Clientes *) realloc(aux, (*qt_clientes + 1) * sizeof(Clientes));
            if( aux == NULL){
                printf("Erro ao alocar\n");
                exit(1);
            }
        
        aux[(*qt_clientes)] = temp;

        (*qt_clientes)++;
    } 

    fclose(p);
    ordenaClientes(&aux, qt_clientes);
    return aux;

}
void inserirPetsClientes(Pet *vetorPets, Clientes *vetorClientes, int qt_pets, int qt_clientes){
    int i, j;
    Pet *pTmp = NULL;
    

    for( i = 0; i < qt_pets; i++){
        for( j = 0; j < qt_clientes; j++){
            if(vetorPets[i].id_cliente == vetorClientes[j].id){

                pTmp = (Pet *) realloc(vetorClientes[j].pets, (vetorClientes[j].qtd_pets + 1) * sizeof(Pet));
                if(pTmp == NULL){
                    printf("Sem memoria\n");
                    free(vetorClientes[j].pets);
                    exit(2);
                }

                vetorClientes[j].pets = pTmp;

                vetorClientes[j].pets[vetorClientes[j].qtd_pets] = vetorPets[i];

                vetorClientes[j].qtd_pets++;

            }
        }
    }
}
void consultaCliente(Clientes *vetorClientes, int id){
  // Fazer seguindo a caonsulta dos pokemons
  int i = 0;

  do{
      if (id == vetorClientes[i].id){
          printf("Esse cliente está cadastrado\n");

      }
      i++;
  }while(i != id);
}
void consultaPet(Pet *vetorPets, int id){
  // Fazer seguindo a caonsulta dos pokemons]
   int i = 0;

  do{
      if (id == vetorPets[i].id_pet){
          printf("Esse pet está cadastrado\n");

      }
      i++;
  }while(i != id);
}

void Menu(){
    int opcao;
    Pet *lista = NULL;
    Clientes *banco_dados = NULL;
    int qtd_pets = 0, qtd_clientes = 0, i;
    int id;

    do{
        printf("\t---CIN PET SHOP---\n");
        printf("1... Carregar os dados no sistema\n");
        printf("2... Inserir pets aos donos\n");
        printf("3... Consultar cliente\n");
        printf("4... Consultar pet\n");
        printf("5... Sair\n");
        printf("Opcao>> ");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            banco_dados = leituraClientes(&qtd_pets);
            lista = leituraPets(&qtd_clientes);
            printf("Dados carregados no sistema :)\n");
        break;
        case 2:

            inserirPetsClientes(lista, banco_dados, qtd_pets, qtd_clientes);

        break;
        case 3:
        scanf("%d", &id);
        consultaCliente(banco_dados, id);

        break;
        case 4:
        scanf("%d", &id);
        consultaPets(lista, id);
        break;
        
        default:
            printf("Entre com uma opcao valida\n");
            break;
        }

    }while(opcao != 5);
    
    for( i = 0; i < qtd_clientes; i++){
        free(banco_dados[i].pets);
    }

    free(banco_dados);
    free(lista);

}

int main(){

    Menu();

    return 0;
}