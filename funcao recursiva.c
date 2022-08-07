#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int fib(int n){
    if(n == 1 || n == 2)
    return 1;
    return fib(n - 1) + fib(n - 2);
}

int fatorial(int n){
    if(n == 1 || n == 2)return 1;
    return n * fatorial(n - 1);
}