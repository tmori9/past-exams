#include <stdio.h>
#include <math.h>

void powerset(char x[], int n){
    int i,j,a;

    for (i=0; i<pow(2, n); i++){
        printf("{ ");
        a=i; //aは10進数
        for(j=0; j<n; j++){
            if(a % 2 == 1){
                printf("%c ", x[j]); // 2進数の桁 
            }
            a /= 2;
        }
        printf("}\n");
    }
}

int main(){
    char x[] = {'a', 'b', 'c'};
    int n=3;
    powerset(x, n);
    return 0;
}