#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
    struct _Node *leftChild;
    struct _Node *rightChild;
    int key;
} Node;

Node *makeNode(int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    node->leftChild = NULL;
    node->rightChild = NULL;
    node->key = data;  
    return node;
}

void preOrder(Node *r) {
    if (r != NULL) {
        printf("%d ", r->key);
        preOrder(r->leftChild);
        preOrder(r->rightChild);
    }
}

void insert_bst(Node *r, int v) {
    if (r == NULL) return;
    if (r->key == v) return;  

    if (v < r->key) {
        if (r->leftChild == NULL) {
            r->leftChild = makeNode(v);
        } else {
            insert_bst(r->leftChild, v);
        }
    } else {
        if (r->rightChild == NULL) {
            r->rightChild = makeNode(v);
        } else {
            insert_bst(r->rightChild, v);
        }
    }
}

int main() {
    char c[30];
    int x;
    
  
    scanf("%s", c);
    scanf("%d", &x);
    
    Node *root = makeNode(x);

    while (scanf("%s", c)) {
        if (!strcmp(c, "#")) {
            break;
        }
        scanf("%d", &x);
        insert_bst(root, x);
    }

    preOrder(root);
    return 0;
}

