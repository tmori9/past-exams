# include <stdio.h>

int check(int *queen, int n, int pos){
    int i, flg=1;
    for (i=0; i<n; i++){
        if (queen[i]/8==pos/8 || queen[i]%8==pos%8 ||
           (queen[i]%9==pos%9 && queen[i]%8<pos%8) ||
           (queen[i]%7==pos%7 && queen[i]%8>pos%8))
           flg=0;
    }
    return flg;
}

int solve(int *queen, int n){
    int i, pos, sum=0;
    if(n<8){
        for (pos= (n==0 ? 0 : queen[n-1]+1); pos<64; pos++)
            if(check(queen, n, pos)){
                queen[n]=pos;
                sum+=solve(queen, n+1);
            }
    }
    else
        sum=1;
    
    return sum;
}

int main(){
    int queen[8];
    printf("The number of solutions is %d. \n", solve(queen, 0));
}