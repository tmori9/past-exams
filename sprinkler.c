#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define NSAMPLES 5000

const double pcloudy = 0.5,
             psprinkler_cloundy1 = 0.1, psprinkler_cloundy0 = 0.5,
             prain_cloundy1 = 0.8, prain_cloundy0 = 0.2,
             pwet_sprinkler1_rain1 = 0.99, pwet_sprinkler1_rain0 = 0.9,
             pwet_sprinkler0_rain1 = 0.9, pwet_sprinkler0_rain0 = 0.0;

struct sample{
    int cloundy;
    int sprinkler;
    int rain;
    int wet;
};

double rand1(void){
    return rand()/(RAND_MAX+1.0);
}

void generate_samples (struct sample s[], int n) {
    int j;
    srand((unsigned int) time(NULL));
    for (j = 0; j < n; j++){
        if (rand1() < pcloudy){
            s[j].cloundy = 1; // a
            if (rand1() < psprinkler_cloundy1) s[j].sprinkler=1;
            if (rand1() < prain_cloundy1) s[j].rain=1;
        } else {
            if (rand1() < psprinkler_cloundy0) s[j].sprinkler=1;
            if (rand1() < prain_cloundy0) s[j].rain=1;
        }

        if ((s[j].sprinkler==1) && (s[j].rain==1)){
            if (rand1() < pwet_sprinkler1_rain1) s[j].wet=1;
        } else if ((s[j].sprinkler==1) && (s[j].rain==0)){
            if (rand1() < pwet_sprinkler1_rain0) s[j].wet=1;
        } else if ((s[j].sprinkler==0) && (s[j].rain==1)){
            if (rand1() < pwet_sprinkler0_rain1) s[j].wet=1;
        } else {
            if (rand1() < pwet_sprinkler0_rain0) s[j].wet=1;
        }
    }
}

int main(void){
    int i, ncloudy=0, nwet=0;
    struct sample samples[NSAMPLES];
    for (i = 0; i < NSAMPLES; i++){
        samples[i].cloundy=0;
        samples[i].sprinkler=0;
        samples[i].rain=0;
        samples[i].wet=0;
    }
    generate_samples(samples, NSAMPLES);
    for (i=0; i<NSAMPLES; i++){
        if (samples[i].wet == 1){
            nwet++;
            if(samples[i].cloundy == 1) ncloudy++;
        }
    }
    printf("%f\n", (double)ncloudy/nwet);
}