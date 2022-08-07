#include <stdio.h>
#include <string.h>

int main()
{
    int i, j;
    int ordem;
    sacanf ("%d", &ordem);
    int mat[ordem][ordem];
    for(i = 0; i<ordem; i++){
        for(j = 0; j<ordem; j++){
            scanf("%d", &mat[i][j]);
        }
    }

    return 0;
}