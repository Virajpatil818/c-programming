#include <stdio.h>

int abc(int,int);

void main(){
    int a=10,b,c;
    //a++;
   // b=a++; // it pass and increment
    c=++a; // it increment and pass
    printf("%d \n",a);
    printf("%d \n",b);
    printf("%d \n",c);
}
