#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char remetente[50];
    char assunto[50];
    char mensagem[200];
} Email;

typedef struct{
    char nome[50];
    char senha[50];
    int qtdRecebidos, qtdEnviados;
    Email *recebidos;
    Email *enviados;
} Usuario;

void cadastrarUsuario(char *nome, char *senha); // 1
void login(char *nome, char *senha);            // 2
void enviarEmail(char *nomeRemetente);          // 3
void verRecebidos(Usuario usuario);             // 4
void verEnviados(Usuario usuario);              // 5

int main(){
    // declarando variaveis
    int opcao;
    int qtdUsers = 0;
    char auxNome[50];
    char auxSenha[50];
    char auxUser[50];
    char auxSenha2[50];

    Usuario *user = NULL;
    user = (Usuario *)malloc(1 * sizeof(Usuario));
    if (user == NULL){
        printf("Erro ao alocar");
        exit(-1);
    }

    FILE *file = NULL;
    file = fopen("users.bin", "wb");
    if (file == NULL){
        printf("arquivo not found");
        exit(0);
    }
    fclose(file);

    // menu
    do{
        printf("\t--- MENU ---\n");
        printf("1... Sign up\n");
        printf("2... Login\n");
        printf("3... Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao){
        case 1:
            if (qtdUsers == 0){ // posição inicial

                printf("Digite o nome do novo usuario >>> ");
                scanf(" %49[^\n]", user[qtdUsers].nome);
                strcpy(auxNome, user[qtdUsers].nome);

                printf("Digite a senha >>> ");
                scanf(" %49[^\n]", user[qtdUsers].senha);
                strcpy(auxSenha, user[qtdUsers].senha);

                cadastrarUsuario(auxNome, auxSenha);
                qtdUsers++;

            }else{ // outras posições pra dar realloc

                user = (Usuario *)realloc(user, (qtdUsers) * sizeof(Usuario)); // atualizando a qtd
                if (user == NULL){
                    printf("Erro ao alocar");
                    exit(1);
                }

                printf("Digite o nome do novo usuario >>> ");
                scanf(" %49[^\n]", user[qtdUsers].nome);
                strcpy(auxNome, user[qtdUsers].nome);

                printf("Digite a senha >>> ");
                scanf(" %49[^\n]", user[qtdUsers].senha);
                strcpy(auxSenha, user[qtdUsers].senha);

                cadastrarUsuario(auxNome, auxSenha);

                qtdUsers++;
            }

            break;

        case 2:
            printf("\nDigite o nome de usuario que deseja logar >>> ");
            scanf(" %49[^\n]", auxUser);
            printf("Agora, digite a senha >>> ");
            scanf(" %49[^\n]", auxSenha2);
            login(auxUser, auxSenha2);
            break;
            
        case 3:
            printf("Obrigada por escolher nosso sistema!\nAte mais!\n");
            free(user);
            break;

        default:
            printf("Opcao invalida, digite novamente.\n");
            break;
        }

    } while (opcao != 3);

    return 0;
}

void cadastrarUsuario(char *nome, char *senha){

    Usuario temp;
    FILE *file = NULL;

    file = fopen("users.bin", "ab+");
    if (file == NULL){
        printf("arquivo not found");
        exit(2);
    }

    strcpy(temp.nome, nome);
    strcpy(temp.senha, senha);
    temp.qtdRecebidos = 0;
    temp.qtdEnviados = 0;
    temp.recebidos = NULL;
    temp.enviados = NULL;

    if (fwrite(&temp, sizeof(Usuario), 1, file) == 1){
        printf("\nCadastro realizado com sucesso :)\n\n");
    }else{
        printf("\nErro ao gravar usuario no arquivo\n\n");
    }

    fclose(file);
}

void login(char *nome, char *senha){
    int u, s, i = 0, choice, flag = 0;
    char sn;
    char rem[50];

    //lendo arq bin
    Usuario aux;
    Usuario *cadastrados = NULL;
    int qtd = 0;

    FILE *file = NULL;
    file = fopen("users.bin", "rb");
    if (file == NULL){
        printf("arquivo not found");
        exit(3); 
    }        

    while (fread(&aux, sizeof(Usuario), 1, file) != 0){

        cadastrados = (Usuario *)realloc(cadastrados, (qtd + 1) * sizeof(Usuario));
        if (cadastrados == NULL){
            exit(4);
        }        
        cadastrados[qtd] = aux;
        qtd++;
    }

    fclose(file);

    /*  for (int i = 0; i < qtd; i++){
        printf("%d:\n", i+1);
        printf("nome: %s\n", cadastrados[i].nome);
        printf("senha: %s\n", cadastrados[i].senha);
    }  */
    //a leitura funciona! :)

    for( i = 0; i < qtd; i++ && flag != 1){
        u = strcmp(cadastrados[i].nome, nome);
        s = strcmp(cadastrados[i].senha, senha);
        if( u == 0 && s == 0){
            do{
                printf("\t...Login efetuado com sucesso!...\n");
                printf("O que deseja fazer agora, %s?\n", nome);
                printf("1... Enviar email\n");
                printf("2... Ver emails recebidos\n");
                printf("3... Ver emails enviados\n");
                printf("4... Sair\n");
                printf("Opcao: ");
                scanf("%d", &choice);

                switch (choice){
                case 1:
                    printf("Digite o user do remetente >>> ");
                    scanf(" %49[^\n]", rem);
                    //enviarEmail(rem); 
                    cadastrados[i].qtdEnviados++;
                    break;

                case 2:
                    //verRecebidos(*cadastrados[i]);
                    break;

                case 3:
                    //verEnviados(*cadastrados[i])
                    break;

                case 4:
                    printf("Ate logo! :)\n");
                    break;

                default:
                    printf("Opcao invalida, digite novamente.\n");
                    break;
                }

            }while(choice != 4);

        }else{

            printf("User ou senha incorretos. Deseja tentar novamente?\n Digite 's' ou 'n' >> ");
            scanf(" %c", &sn);
            if( sn == 's'){
                printf("user >>> ");
                scanf(" %49[^\n]", nome);
                printf("senha >>> ");
                scanf(" %49[^\n]", senha);
                login(nome, senha);
            }
        }
    }
}

void enviarEmail(char *nomeRemetente){
    Email email;
    int j, u;
    char destinatario[50];
    //lendo arq
    Usuario aux;
    Usuario *cadastrados = NULL;
    int qtd = 0;
    int flag = 0;
    
    FILE *file = NULL;
    file = fopen("users.bin", "rb");
    if (file == NULL){
        printf("arquivo not found");
        exit(3); 
    }        

    while (fread(&aux, sizeof(Usuario), 1, file) != 0){
        cadastrados = (Usuario *)realloc(cadastrados, (qtd + 1) * sizeof(Usuario));
        if (cadastrados == NULL){
            exit(4);
        }        
        cadastrados[qtd] = aux;
        qtd++;
    }
    fclose(file);

    printf("Qual o user do destinatario? >> ");
    scanf(" %49[^\n]", destinatario);
    printf("Qual o assunto? >> ");
    scanf(" %49[^\n]", email.assunto);
    printf("Agora, escreva a mensagem:\n");
    scanf("%199[^\n]", email.mensagem);

    for ( j = 0; j < qtd; j++ && flag = 0){
        u = strcmp(destinatario, cadastrados[j].nome);
        if(u == 0){
            cadastrados[j].qtdRecebidos++;
            cadastrados[j].recebidos = (Email *)realloc(cadastrados[j].recebidos, (cadastrados[j].qtdRecebidos)*sizeof(Email));
            cadastrados[j].recebidos[cadastrados[j].qtdRecebidos-1] = email;
            flag = 1;
        }
    }

    


}