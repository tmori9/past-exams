#include <stdio.h>
#include <stdlib.h>
#define N 1000
int calc(int x, int *dp){
    int val;
    if (x<=0) return 1;
    if (dp[x] != 0) return dp[x];
    val = calc(x-2, dp) + calc(x/3 -7, dp);
    if (dp[x] == 0) dp[x] = val;
    return val;
}

int func(int x){
    int i, ans;
    int *dp = calloc(N, sizeof(int));
    for (i=0; i<N; i++) dp[i] = 0;
    ans = calc(x, dp);
    for (i=0; i<50; i++) printf("%d", dp[i]);
    printf("\n");
    free(dp);
    return ans;
}

int main(){
    int x;
    scanf("%d", &x);
    printf("%d\n", func(x));
    return 0;
}