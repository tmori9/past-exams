#include <stdlib.h>
#include <stdio.h>

struct NODE { int value; struct NODE *left; struct NODE *right;};

void insert (struct NODE **p, int n){
    if (*p==NULL){
        if ((*p=(struct NODE *)malloc(sizeof(struct NODE))) == NULL) exit(1);
        (*p) -> value = n;
        (*p) -> left = NULL;
        (*p) -> right = NULL;
    } else {
        if ((*p)->value > n) insert(&(*p) -> left, n);
        else if ((*p)->value < n) insert(&(*p)->right, n);
    }
}

void printnodes (struct NODE *q){
    if (q != NULL){
        printnodes(q->right);
        printf("%d ", q->value);
        printnodes(q->left);
    }
}

int main(){
    int n;
    struct NODE *r=NULL;
    insert(&r, 5); insert(&r, 12); insert(&r, 2); insert(&r, 7);
    insert(&r, 15); insert(&r, 8); insert(&r, 3); insert(&r, 4);
    printnodes(r);
}