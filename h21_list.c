#include <stdlib.h>
#include <stdio.h>

struct LIST { int value; struct LIST *next; };

void insert (struct LIST *cell, int n){
    if (cell->next == NULL || (cell->value%10==n%10)){
        struct LIST *new;
        if ((new = malloc(sizeof(struct LIST))) == NULL) exit(1);
        new->next = cell->next;
        new->value = n;
        cell->next = new;
    }
    else insert(cell->next, n);
}

void delete(struct LIST *cell, int n){
    if (cell!=NULL && cell->next != NULL){
        if (cell->next->value == n){
            struct LIST *old;
            old = cell->next;
            cell->next = old->next;
            free(old);
        }
        else delete(cell->next, n);
    }
}

int main(){
    int n;
    struct LIST root;
    root.next = NULL;
    insert(&root, 52); insert(&root, 18); insert(&root, 32); insert(&root, 91);
    insert(&root, 48); insert(&root, 22); insert(&root, 15); delete(&root, 91);
    printf("%d\n", root);
    return 0;
}