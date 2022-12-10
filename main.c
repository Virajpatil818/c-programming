#include <stdio.h>

int add(int);
int sub(int);
int mul(int);
    
int a1=5;
int a2=10;
int a3=15;

void main(){
    int a,b,c;
    
    add(a);
    sub(b);
    mul(c);
    
    printf(" %d",a);
    printf(" %d",b);
    printf(" %d",c);
    
}

int add(int a){
     a=a1+a2+a3;
    printf(" %d",a);
    return a;
}

int sub(int b){
    b=a1-a2-a3;
    return b;
}

int mul(int c){
    c=a1*a2*a3;
    return c;
}