#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int datatype;
typedef struct _TNode {
    struct _TNode *leftMostChild;
    struct _TNode *rightSibling;
    datatype inf;
} TNode;

// Create a new node with given value
TNode *makeNode(datatype x) {
    TNode *p = (TNode *)malloc(sizeof(TNode));
    if (p == NULL) {
        printf("Error mem location\n");
        exit(1);
    }
    p->inf = x;
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    return p;
}

// Pre-order traversal
void preOrder(TNode *r) {
    if (r == NULL) return;
    printf("%d ", r->inf);
    TNode *p = r->leftMostChild;
    while (p != NULL) {
        preOrder(p);
        p = p->rightSibling;
    }
}

// Post-order traversal
void postOrder(TNode *r) {
    if (r == NULL) return;
    TNode *p = r->leftMostChild;
    while (p != NULL) {
        postOrder(p);
        p = p->rightSibling;
    }
    printf("%d ", r->inf);
}

// In-order traversal
void inOrder(TNode *r) {
    if (r == NULL) return;
    TNode *p = r->leftMostChild;
    inOrder(p);  // Visit leftmost child
    printf("%d ", r->inf);  // Visit root
    if (p != NULL) p = p->rightSibling;
    while (p != NULL) {  // Visit remaining children
        inOrder(p);
        p = p->rightSibling;
    }
}

// Find node with given value
TNode *find(TNode *r, datatype x) {
    if (r == NULL) return NULL;
    if (r->inf == x) return r;
    TNode *p = r->leftMostChild;
    while (p != NULL) {
        TNode *result = find(p, x);
        if (result != NULL) return result;
        p = p->rightSibling;
    }
    return NULL;
}

// Find the rightmost child of the root
TNode *mostRightChild(TNode *r) {
    if (r == NULL) return NULL;
    TNode *p = r->leftMostChild;
    if (p == NULL) {
        return NULL;
    }
    while (p->rightSibling != NULL) {
        p = p->rightSibling;
    }
    return p;
}

int main() {
    char action[20];
    int a, b;
    TNode *root = NULL;

    while (1) {
        scanf("%s", action);
        if (strcmp(action, "*") == 0) break;

        if (strcmp(action, "MakeRoot") == 0) {
            scanf("%d", &a);
            root = makeNode(a);
        } else if (strcmp(action, "Insert") == 0) {
            scanf("%d %d", &a, &b);
            TNode *parent = find(root, b);
            if (parent != NULL && find(root, a) == NULL) {
                TNode *newNode = makeNode(a);
                TNode *rightMost = mostRightChild(parent);
                if (rightMost == NULL) {
                    parent->leftMostChild = newNode;
                } else {
                    rightMost->rightSibling = newNode;
                }
            }
        } else if (strcmp(action, "PreOrder") == 0) {
            preOrder(root);
            printf("\n");
        } else if (strcmp(action, "InOrder") == 0) {
            inOrder(root);
            printf("\n");
        } else if (strcmp(action, "PostOrder") == 0) {
            postOrder(root);
            printf("\n");
        }
    }

    return 0;
}

