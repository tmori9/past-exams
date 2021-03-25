#include <stdio.h>
int fprime(int p){
    int t=1;
    int i;
    for(i=0; i<p-1;i++){
        t *= 2;
        t %= p;
    }
    return t;
}

int prime(int n){
    int i;
    for(i=2; i<n; i++){
        if(n%i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int i;
    for(i=2; i<=1000; i++){
        if (fprime(i)==1 && prime(i)==1)
            printf("%d\n", i);
    }
    return 0;
}