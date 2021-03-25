#include <stdio.h>
long combination(int n, int k){
    int i;
    long c=1;
    for(i=1; i<=k; i++){
        c=c*(n-i+1)/i;
    }
    return c;
}

long combination1(int n, int k){
    if((k==0)||(k==n)){
        return 1;
    } else {
        return (combination1(n-1, k-1) + combination1(n-1, k));
    }
}

int main(){
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    printf("combination(%d, %d) = %ld\n", n, k, combination1(n,k));
}