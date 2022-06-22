#include <stdio.h>

int resto(int n, int d){
    if (n<d)
    {
        return n;
    }
    return resto(n-d, d);
}

int main(){
    int n, d, r;
    n = 11;
    d = 3;
    r = resto(n,d);
    printf("%d\n",r);
    return 0;
}