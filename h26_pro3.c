#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *left, *right;
} node;

node * append(node *n, int x){

    if(n==NULL){
        n = (node *)malloc(sizeof(node));
        n->left = n->right = NULL;
        n->value = x;
        return n;
    }

    if (n->value%x ==0) n->left = append(n->left, x);
    else n->right = append(n->right, x);
    return n;
}

void show(node *n){
    if (n->left != NULL) show(n->left);
    if (n->right != NULL) show(n->right);
    printf("%d\n", n->value);
}

void clear(node *n){
    if(n == NULL) return;
    clear(n->left);
    clear(n->right);
    free(n);
}

int main(){
    node *root = NULL;
    root = append(root, 8);
    root = append(root, 2);
    root = append(root, 3);
    root = append(root, 4);
    root = append(root, 1);
    root = append(root, 6);
    show(root);
    clear(root);
    return 0;
}
