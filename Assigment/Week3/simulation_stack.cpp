#include<stdio.h>
#include<string.h>
#define MAX 1000

char c[MAX];
int stack[MAX];
int top = 0;

int main() {
    int x;
    
    while (scanf("%s", c)) {
        if (!strcmp(c, "PUSH")) {
            scanf("%d", &x);
            stack[top] = x;
            top++;
        } else if (!strcmp(c, "#")) {
            break;
        } else if (!strcmp(c, "POP")) {
            if (top > 0) {
                top--; 
                printf("%d\n", stack[top]);
            } else {
                printf("NULL\n");
            }
        }
    }

    return 0;
}

