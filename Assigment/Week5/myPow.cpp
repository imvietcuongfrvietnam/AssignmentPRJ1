double myPow(double x, int n) {
    // X? l� tru?ng h?p d?c bi?t cho n = INT_MIN
    if (n == INT_MIN) {
        x = 1 / x;
        n = INT_MAX;  // Tang n l�n th�nh gi� tr? duong cao nh?t
        return x * myPow(x, n);  // Nh�n th�m x cho d�ng gi� tr?
    }

    // N?u n l� s? �m, d?o ngu?c x v� bi?n n th�nh duong
    if (n < 0) {
        x = 1 / x;
        n = -n;
    }

    // Co s? d? b?t d?u
    if (n == 0) return 1;
    if (n == 1) return x;

    // T�nh luy th?a b?ng d? quy chia d? tr?
    double half = myPow(x, n / 2);
    if (n % 2 == 0)
        return half * half;
    else
        return half * half * x;
}

