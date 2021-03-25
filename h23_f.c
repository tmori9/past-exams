#include <stdio.h>
#include <stdlib.h>

double f(double x){
    return -x*x*x + 1;
}

double bisection(double (*f)(double), double *zeropoint, double a, double b, double accuracy){
    double fa, fb, mid , fmid;

    fa=f(a); fb=f(b);
    if (fa*fb > 0) return 0;
    if (fa==0) {*zeropoint=a; return 1;}
    if (fb==0) {*zeropoint=b; return 1;}

    while (1){
        printf("%.3f %.3f\n", a, b);

        mid=(a+b)*0.5;
        if (mid-a <= accuracy || b-mid <= accuracy) break;

        fmid =f(mid);
        if (fmid==0) {*zeropoint=mid; return 1;}

        if (fa*fmid < 0) {b=mid; fb=fmid;}
        else {a=mid; fa=fmid;}
    }
    *zeropoint=mid;
    return 1;
}

int main(){
    double x;
    if(bisection(f, &x,-2.000, 2.0000, 0.001))
        printf("%.3f\n", x);
    else
        printf("not zero point.\n");
}