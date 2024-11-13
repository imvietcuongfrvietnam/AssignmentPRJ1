#include <stdio.h>
#include <string.h>
#define MAX 1000000

int number[MAX];
char query[100];
char *query_possible[4] = {"find-max", "find-min", "find-max-segment", "sum"};

int find_max_segment(int i, int j, int s[]) {
    int res = s[i];
    for (int k = i; k <= j; k++) {
        if (s[k] > res) res = s[k];
    }
    return res;
}

int find_min_segment(int i, int j, int s[]) {
    int res = s[i];
    for (int k = i; k <= j; k++) {
        if (s[k] < res) res = s[k];
    }
    return res;
}

int sum(int s[], int n) {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res += s[i];
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &number[i]);
    }

    // Ğ?c kı t? m?i sau khi d?c s? n
    getchar(); // B? qua kı t? '\n'

    while (1) {
        scanf("%s", query);
        if (strcmp(query, "***") == 0) break; // Thoát n?u g?p "***"
        
        for (int i = 0; i < 4; i++) {
            if (strcmp(query, query_possible[i]) == 0) {
                if (i == 0) {
                    printf("%d\n", find_max_segment(1, n, number));
                } else if (i == 1) {
                    printf("%d\n", find_min_segment(1, n, number));
                } else if (i == 2) {
                    int a, b;
                    scanf("%d %d", &a, &b);
                    printf("%d\n", find_max_segment(a, b, number));
                } else {
                    printf("%d\n", sum(number, n));
                }
            }
        }
    }

    return 0;
}

