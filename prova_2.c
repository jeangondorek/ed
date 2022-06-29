#include <stdio.h>

typedef struct
{
    int valorinteiro;
    int casadecimall;
} valor;

valor setFloat(int x, int a){
    valor inteiro;
    inteiro.valorinteiro = x;
    inteiro.casadecimall= a;
    return inteiro;
}

valor sumFloat(valor tf, valor td){
    int casadec, valoorr;
    casadec = tf.casadecimall + td.casadecimall;
    valoorr = tf.valorinteiro + td.valorinteiro;
    if (casadec > 9)
    {
        casadec = casadec - 10;
        valoorr += 1;
    }
    valor result;
    result = setFloat(valoorr,casadec);
    return result;
}

void printFloat(valor tf){
    printf("%d,%d\n", tf.valorinteiro, tf.casadecimall);
}

int main(){
    valor tf, r;
    tf = setFloat(10,6);
    r = sumFloat(tf, tf);
    printFloat(tf);
    printFloat(r);
    return 0;
}