#include <stdio.h>
#include <string.h>
#define TAM 7

int main()
{
    int i = 0, j = 0, temp;
    int vetorOriginal[TAM] = {5, 6, 2, 4, 1, 3};
    int vetorCrescente[TAM], maior;
    int vetorDecrescente[TAM], menor;


    for (i = 0; i < TAM  ; i++){
       vetorCrescente[i] = vetorOriginal[i];
   }
   
//for (int k = 0; k < TAM; k++)
      for (i = 0; i < TAM-1  ; i++){

        for (j = i+1; j < TAM; j++){

           if (vetorCrescente[i] > vetorCrescente[j] ){
            temp = vetorCrescente[i];
            vetorCrescente[i] = vetorCrescente[j];
            vetorCrescente[j] = temp;
           }
        }
        
      }
      printf("%d %d %d %d %d %d\n", vetorCrescente[0], vetorCrescente[1], vetorCrescente[2], vetorCrescente[3], vetorCrescente[4], vetorCrescente[5] );
 for (i = 0; i < TAM  ; i++){
       vetorDecrescente[i] = vetorOriginal[i];
   }
   

      for (i = 0; i < TAM ; i++){

        for (j = i+1; j < TAM; j++){

           if (vetorDecrescente[i] < vetorDecrescente[j]){
            temp = vetorDecrescente[i];
            vetorDecrescente[i] = vetorDecrescente[j];
            vetorDecrescente[j] = temp;
           }
        }
      }
    return 0;
}