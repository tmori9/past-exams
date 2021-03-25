#include <stdio.h>
#include <math.h>

double maxdist(double x[], double y[], int n){
    int i;
    double max = x[0]*x[0] + y[0]*y[0], m;
    printf("%lf\n", max);
    for (i=1; i<n; i++){
        m = x[i]*x[i] + y[i]*y[i];
        printf("%lf\n", m);
        if (max < m){
            max = m;
        }
    }
    max = sqrt(max);
    return max;
}

int main(){
    double x[] = {6.0, -3.3, -5.7};
    double y[] = {1.9, 5.4, -2.6};

    printf("%lf\n", maxdist(x, y, 3));
    return 0;
}