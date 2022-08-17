#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buscaBinaria(int *l, int inicio, int fim, int key){
    int meio;
    if (inicio>fim){
        return -1;
    }
    meio = (inicio+fim)/2;
    if (l[meio] == key)    {
        return meio;
    }
    if (key > l[meio])    {
        return buscaBinaria(l, meio+1, fim, key);
    }
    else{
        return buscaBinaria(l, inicio, meio-1, key);
    }
     
}

int main(){
    int ret;
    int inicio=0, fim=1200000;
    int l[fim];
    int key = 119;
    for (int i = 0; i <= fim; i++)
    {
        l[i]=i;
    }
    ret = buscaBinaria(l, inicio, fim, key);
    printf("%d\n", ret);
    return 0;
}