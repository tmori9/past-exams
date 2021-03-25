#include <stdio.h>

void swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void shiftdown(int *n, int cur, int btm){
    int largerChild;

    while ((2*cur + 1) <= btm){
        if((2*cur + 1) == btm || n[2*cur + 1] > n[2*cur + 2])
            largerChild = 2*cur + 1;
        else
            largerChild = 2*cur + 2;
        
        if (n[cur]<n[largerChild]){
            swap(n+cur, n+largerChild);
            cur = largerChild;
        }
        else
            break;
    }
}

void sort(int *n, int num){
    int i;

    for(i=(num-2)/2; i>=0; i--)
        shiftdown(n, i, num-1);
    
    for (i=0; i<10; i++){
        printf("%d\n", n[i]);
    }
    
    for (i=num-1; i>0; i--){
        swap(n, n+i);
        shiftdown(n, 0, i-1);
    }
}

void main(){
    int n[] = {10, 2, 6, 4, 8, 9, 1, 3, 7, 5};
    sort(n, 10);
}