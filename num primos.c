#include <stdio.h>
#include <string.h>
#define TAM 50

int main()
{
    int i, x, y, flag = 0;

    for (x = 0; x < TAM; x++ ){
        for(y = 0; y < TAM; y++){
            flag = 0;
    
        if ((y == 1 || y%2 == 0) && (y != 2))
            flag = 1;
        else{
        for (i = 3; i < y/2 && flag == 0; i+= 2){
            if (y%i == 0){
                
                flag = 1;
            }

        }   
        if (flag == 0){

        }


        }
    }

    return 0;
}