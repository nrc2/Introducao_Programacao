#include <stdio.h>
#include <string.h>
#define TAM 10

int main()
{
    int i, N, j, z, temp = 0;
    char lc[TAM][10]; 

     for(i=0;i<TAM;i++){

        scanf(" %s", lc[i]);
    
    }

     for(i=0;i<TAM - 1;i++){
        for(j=i+1;j<TAM;j++){
            z=strcmp(lc[i], lc[j]);
            if(z>0){                            
                strcpy(temp, lc[i]);
                strcpy(lc[i], lc[j]);
                strcpy(lc[j], temp);
            }            
        }
    }
    printf (" %s", lc[0]);
    

    return 0;
}