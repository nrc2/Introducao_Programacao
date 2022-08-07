#include <stdio.h>
#include <string.h>
#define TAM 4

int main()
{

    char palavra[15] = "mao";
    char tabuleiro[TAM][TAM];
    char encontrei = 0;
    int linha, coluna, tmp, tam;

    for (linha = 0; linha < TAM && !encontrei; linha++)
    {
        for (coluna = 0; coluna < TAM && !encontrei; coluna++)
        {
            scanf(" %c", &tabuleiro[linha][coluna]);
        }
    }

    printf("CACA - PALAVRAS\n");
    for (linha = 0; linha < TAM && !encontrei; linha++)
    {
        for (coluna = 0; coluna < TAM && !encontrei; coluna++)
        {
            printf(" %c", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    tam = strlen(palavra);
    for (linha = 0; linha < TAM && !encontrei; linha++)
    {
        for (coluna = 0; coluna < TAM && !encontrei; coluna++)
        {
            if (tabuleiro[linha][coluna] == palavra[0])
            {
                // Encontrei o 1o caractere
                for (tmp = 1;
                     tabuleiro[linha][coluna + tmp] == palavra
                                                           [tmp] &&
                     tabuleiro[linha][coluna + tmp] != '\0' && tmp != tam && (tmp + coluna) != TAM && palavra[tmp] != '\0';
                     tmp++)
                    ;
                if (palavra[tmp] == '\0')
                {
                    printf("Encontreil!! e-d\n"); // Palavra da esquerda para a direita
                    encontrei = 1;
                }
                for (tmp = 1;
                     tabuleiro[linha][coluna - tmp] == palavra
                                                           [tmp] &&
                     palavra[tmp] != '\0';
                     tmp++)
                    ;
                if (palavra[tmp] == '\0')
                {
                    printf("Encontreil!! d-e\n"); // Palavra da direita para a esquerda
                    encontrei = 1;
                }
                for (tmp = 1;
                     tabuleiro[linha + tmp][coluna + tmp] == palavra
                                                                 [tmp] &&
                     palavra[tmp] != '\0';
                     tmp++)
                    ;
                if (palavra[tmp] == '\0')
                {
                    printf("Encontreil!!c - b\n"); // Palavra na diagonal de cima para baixo
                    encontrei = 1;
                }
                for (tmp = 1;
                     tabuleiro[linha - tmp][coluna - tmp] == palavra
                                                                 [tmp] &&
                     palavra[tmp] != '\0';
                     tmp++)
                    ;
                if (palavra[tmp] == '\0')
                {
                    printf("Encontreil!!b - c\n"); // Palavra na diagonal de baixo para cima
                    encontrei = 1;
                }
            }
        }
    }

    return 0;
}