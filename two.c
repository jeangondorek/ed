#include <stdio.h>

typedef struct
{
    double real;
    double imaginario;
} complexa;

complexa setComplex(double r, double i){
    complexa c;
    c.real = r;
    c.imaginario = i;
    return c;
}

complexa sumComplex(complexa a, complexa b){
    complexa soma;
    soma.imaginario=a.imaginario + b.imaginario;
    soma.real = a.real + b.real;
    return soma;
}

void printComplex(complexa a){
    printf("(%lf + %lf i)\n", a.real, a.imaginario);
}

int main(){
    double n, d;
    complexa cp,sc;
    n = 11;
    d = 3;
    cp = setComplex(n, d);
    sc = sumComplex(cp, cp);
    printComplex(cp);
    return 0;
}