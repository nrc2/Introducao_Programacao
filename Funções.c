#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double DistanciaEntrePontos(double x1, double y1, double x2, double y2);
void preencheVet(float *vet);

int main(){
    float num = 16;
    printf("%lf\n", DistanciaEntrePontos(0, 1, 3, 1));
    preencheVet(&num);
    printf("vet = %f\n", num);


    return 0;
}

double DistanciaEntrePontos(double x1, double y1, double x2, double y2){
    double dx = (x1  - x2) * (x1 - x2);
    double dy = (y1 - y2) * (y1 - y2);
    double dist = sqrt (dx + dy);
     
     return dist;

}
void preencheVet(float *vet){
    printf ("digite um elemento: ");
    scanf ("%f", vet);
}
