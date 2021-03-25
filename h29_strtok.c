#include<stdio.h>
#define MAX_LENGTH 20

int split(char *str, char *list[], const char delimiter){
    int index = 0;
    list[index++] = str;

    //printf("index = %d\n", index);
    
    //printf("%p\n", *list[0]);
    //printf("list: %s\n", list[0]);
    //printf("%p\n", *str);
    //printf(str);
    //printf("\n");

    while (*(str+1) != '\0')
    {
        //printf("pointaOfstr: %p\n", *str);
        str++;

        //printf("%c\n", str[0]);
        if(str[0] == delimiter){
            *str = '\0';
            list[index] = str+1;
            index++;
            if (index==MAX_LENGTH) break;
        }
    }
    //printf("list[0]: %s\n", list[0]);
    //printf("list[1]: %s\n", list[1]);
    //printf("list[2]: %s\n", list[2]);
    //printf("list[3]: %s\n", list[3]);

    return index;
}

int main(){
    char str[] ="One,Two,Three,Four,q,w,e,r,t,y,u,i,o,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,d";
    char *result[MAX_LENGTH];
    int length;
    length =split(str, result, ',');
    //printf("----for-----\n");
    for (int i=0; i<length; i++){
        printf("%s\n", result[i]);
    }
    return 0;
}