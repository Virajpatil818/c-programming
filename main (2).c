#include <stdio.h>

int abc(int,int);

void main(){
    int a=5,b=2,c,d;
    //a++;
    // b=a++; // it pass and increment
    // c=++a; // it increment and pass
    
    c=a&b;
    d=a|b;
    
    
    printf("%d \n",c);
    printf("%d \n",d);
   // printf("%d \n",c);
}
