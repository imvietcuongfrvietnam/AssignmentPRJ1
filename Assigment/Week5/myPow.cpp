double myPow(double x, int n) {
    // X? lý tru?ng h?p d?c bi?t cho n = INT_MIN
    if (n == INT_MIN) {
        x = 1 / x;
        n = INT_MAX;  // Tang n lên thành giá tr? duong cao nh?t
        return x * myPow(x, n);  // Nhân thêm x cho dúng giá tr?
    }

    // N?u n là s? âm, d?o ngu?c x và bi?n n thành duong
    if (n < 0) {
        x = 1 / x;
        n = -n;
    }

    // Co s? d? b?t d?u
    if (n == 0) return 1;
    if (n == 1) return x;

    // Tính luy th?a b?ng d? quy chia d? tr?
    double half = myPow(x, n / 2);
    if (n % 2 == 0)
        return half * half;
    else
        return half * half * x;
}

