#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 10

void main(){
    unsigned long i, number;
    int **binary, **gray, length, j;

    printf("length = ");
    scanf("%d", &length);

    if(length > MAX_LENGTH){
        printf("length exceeds a limit (%d).\n", MAX_LENGTH);
        exit(1);
    }

    number = (unsigned long)1 << length;
    printf("number = %ld\n", number);

    binary = (int **)malloc(sizeof(int *) * number);
    gray = (int **)malloc(sizeof(int *) * number);

    for(i=0; i<number; i++){
        binary[i] = (int *)malloc(sizeof(int *) * length);
        gray[i] = (int *)malloc(sizeof(int *) * length);
        for(j=0; j<length; j++) binary[i][j] = (i >> j) & 1;
        gray[i][length-1] = binary[i][length-1]; // 最後だけbinaryと同じにする
        for(j=length-2; j>=0; j--) gray[i][j] = (binary[i][j+1] ^ binary[i][j]);
    }

    for(i = 0; i < number; i++){
        printf("number=%d : ", i);
        for(j=length-1; j>=0; j--) printf("%d", binary[i][j]);
        printf(" : ");
        for(j=length-1; j>=0; j--) printf("%d", gray[i][j]);
        printf("\n");
    }

    for(i=0; i<number; i++){
        free(binary[i]);
        free(gray[i]);
    }
    free(binary);
    free(gray);
}