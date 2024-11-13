#include <stdio.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    while (n--) {
        char string[201]; // mỗi chuỗi có chiều dài tối đa là 200 ký tự
        scanf("%s", string);
        int len = strlen(string);
        long long hash = 0; // sử dụng long long để tránh tràn số khi tính toán

        for (int i = 0; i < len; i++) {
            hash = (hash * 256 + string[i]) % m;
        }

        printf("%lld\n", hash);
    }

    return 0;
}
