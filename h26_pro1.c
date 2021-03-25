#include <stdio.h>
int check(int n){
    int i;
    for (i=1; i*i<=n; i++){
        if (i*i == n) return i;
    }
    return 0;
}

int main(){
    int x, y, z;
    for (x=1; x<=20; x++){
        for (y=1; y<=20; y++){
            z = check(x*x + y*y);
            if(z!=0) printf("x=%d, y=%d, z=%d\n", x, y, z);
        }
    }
    return 0;
}