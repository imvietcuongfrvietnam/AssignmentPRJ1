#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;  // Nh?p chu?i

    // Ki?m tra d? d�i chu?i
    if (s.length() != 10) {
        printf("INCORRECT\n");
        return 0;
    }

    // Ki?m tra d?nh d?ng d?u '-'
    if (s[4] != '-' || s[7] != '-') {
        printf("INCORRECT\n");
        return 0;
    }

    // T�nh to�n nam, th�ng, ng�y
    int years = (s[0] - '0') * 1000 + (s[1] - '0') * 100 + (s[2] - '0') * 10 + (s[3] - '0');
    int month = (s[5] - '0') * 10 + (s[6] - '0');
    int day = (s[8] - '0') * 10 + (s[9] - '0');

    // Ki?m tra th�ng v� ng�y h?p l?
    if (month < 1 || month > 12 || day < 1 || day > 31) {
        printf("INCORRECT\n");
        return 0;
    }

    if (month == 2) { // Th�ng 2
        // Ki?m tra nam nhu?n
        bool isLeapYear = (years % 4 == 0 && years % 100 != 0) || (years % 400 == 0);
        if (day > (isLeapYear ? 29 : 28)) {
            printf("INCORRECT\n");
            return 0;
        }
    } else {
        // Ki?m tra c�c th�ng c� 30 ng�y
        if (month == 4 || month == 6 || month == 9 || month == 11) {
            if (day > 30) {
                printf("INCORRECT\n");
                return 0;
            }
        }
    }
	printf("%d %d %d", years, month, day);

    return 0;
}

