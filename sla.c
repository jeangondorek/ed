#include <stdio.h> 
#include <string.h>

void FirstReverse(char str[]) {
  int tam;
  tam = strlen(str);
    for(int i = 0 ;tam > i; tam= tam-1){
    printf("%c", str[tam]);
  }
  // code goes here  
  printf("%s", str);

}

int main(void) { 
   
  // keep this function call here
  FirstReverse("coderbyte");
  return 0;
    
}