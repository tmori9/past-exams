# include <stdio.h>

int sumd(int x){
    int i, s;
    s = 0;
    for (i=1; i<x; i++){
        if (x%i == 0){
            s += i;
        }
    }
    return s;
}

int main(){
    int i;

    for (i=1; i<10000; i++){
        if (sumd(i) == i ){
            printf("%d\n", i);
        }
    }
    return 0;
}