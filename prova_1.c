#include <stdio.h>

int resto(int n, int d, int r){
    if (n<d)
    {
        return r;
    }
    return resto(n-d, d, r+1);
}
//
int main(){
    int n, d, r;
    r = 0;
    n = 12;
    d = 3;
    r = resto(n,d, r);
    printf("%d\n",r);
    return 0;
}