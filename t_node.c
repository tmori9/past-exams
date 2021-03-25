#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 100
#define SUBLEN 3

struct t_node
{
    char *substring;
    int count;
    struct t_node *left;
    struct t_node *right;
};

struct t_node *t_alloc(void){
    return (struct t_node *) malloc(sizeof(struct t_node));
};

struct t_node *add_tree(struct t_node *p, char *w){
    int cond;
    if (p==NULL){
        p=t_alloc();
        p->substring = (char *) malloc(SUBLEN+1);
        strcpy(p->substring, w);
        p->count=1;
        p->left=p->right=NULL;
    }else if ((cond=strcmp(w, p->substring))==0)
        p->count++;
    else if (cond < 0)
        p->left=add_tree(p->left, w);
    else
        p->right=add_tree(p->right, w);
    
    return p;
}

void tree_print(struct t_node *p){
    if(p != NULL){
        tree_print(p->left);
        printf("%s %d\n", p->substring, p->count);
        tree_print(p->right);
    }
}

int main(void){
    int i,j;
    char string[MAXLEN];
    int length;
    char sub[SUBLEN+1];
    struct t_node *root;

    root = NULL;
    printf("input: ");
    scanf("%s", string);
    length=strlen(string);
    //printf("length: %d", length);
    if(SUBLEN>length){
        return 0;
    }else{
        for(i=0; i<length-SUBLEN+1; i++){
            for(j=0; j<SUBLEN; j++){
                sub[j] = string[j+i];
            }
            sub[SUBLEN]='\n';
            root=add_tree(root, sub);
        }
    }
    tree_print(root);
    return 0;
}