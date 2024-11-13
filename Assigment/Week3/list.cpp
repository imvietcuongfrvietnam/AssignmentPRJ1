#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100

typedef struct _Node {
    struct _Node *next;
    int key;
} Node;

char c[MAX];

int exists(Node *head, int key) {
    Node *tmp = head;
    while (tmp != NULL) {
        if (tmp->key == key) return 1;
        tmp = tmp->next;
    }
    return 0;
}

Node* addLast(Node *head, int key) {
    if (exists(head, key)) return head;
    Node *p = (Node*)malloc(sizeof(Node));
    p->key = key;
    p->next = NULL;
    if (head == NULL) return p;
    Node *tmp = head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = p;
    return head;
}

Node* addHead(Node *head, int key) {
    if (exists(head, key)) return head;
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = head;
    return newNode;
}

Node* find(Node *head, int key) {
    Node *tmp = head;
    while (tmp != NULL) {
        if (tmp->key == key) return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

Node* findBefore(Node *head, int key) {
    Node *tmp = head;
    if (head == NULL || head->next == NULL) return NULL;
    while (tmp->next != NULL && tmp->next->key != key) {
        tmp = tmp->next;
    }
    return tmp;
}

Node* addAfter(Node *head, int key, int val) {
    if (!exists(head, val) || exists(head, key)) return head;
    Node *tmp = find(head, val);
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = tmp->next;
    tmp->next = newNode;
    return head;
}

Node* addBefore(Node *head, int key, int val) {
    if (!exists(head, val) || exists(head, key)) return head;
    if (head->key == val) {
        return addHead(head, key);
    }
    Node *tmp = findBefore(head, val);
    if (tmp == NULL) return head;
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = tmp->next;
    tmp->next = newNode;
    return head;
}

Node* removeKey(Node *head, int key) {
    if (!exists(head, key)) return head;
    if (head->key == key) {
        Node *tmp = head;
        head = head->next;
        free(tmp);
        return head;
    }
    Node *tmp = findBefore(head, key);
    if (tmp->next != NULL) {
        Node *p = tmp->next;
        tmp->next = tmp->next->next;
        free(p);
    }
    return head;
}

Node* reverse(Node *head) {
    Node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void printList(Node *head) {
    Node *p = head;
    while (p != NULL) {
        printf("%d ", p->key);
        p = p->next;
    }
    printf("\n");
}

int main() {
    int n, input;
    scanf("%d", &n);
    Node *head = NULL;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &input);
        head = addLast(head, input);
    }

    int input2;
    while (1) {
        scanf("%s", c);
        if (!strcmp(c, "#")) break;

        if (!strcmp(c, "addfirst")) {
            scanf("%d", &input);
            head = addHead(head, input);
            
        } 
        else if (!strcmp(c, "addlast")) {
            scanf("%d", &input);
            head = addLast(head, input);
            
        } 
        else if (!strcmp(c, "addafter")) {
            scanf("%d%d", &input, &input2);
            head = addAfter(head, input, input2);
         
        } 
        else if (!strcmp(c, "addbefore")) {
            scanf("%d%d", &input, &input2);
            head = addBefore(head, input, input2);
          
        } 
        else if (!strcmp(c, "remove")) {
            scanf("%d", &input);
            head = removeKey(head, input);
       
        } 
        else if (!strcmp(c, "reverse")) {
            head = reverse(head);
         
        }
    }
	printList(head);
    return 0;
}

