int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *result = (int*)malloc(sizeof(int) * (digitsSize + 1));
    int c = 1;  // Gi� tr? carry ban d?u l� 1 v� c?ng th�m 1 v�o s?

    // T�nh to�n t? ch? s? cu?i c�ng d?n ch? s? d?u ti�n
    for (int i = digitsSize - 1; i >= 0; i--) {
        result[i + 1] = (digits[i] + c) % 10;
        c = (digits[i] + c) / 10;
    }

    // N?u c�n carry sau khi l?p
    if (c == 1) {
        result[0] = 1;
        *returnSize = digitsSize + 1; // C?n th�m m?t ch? s? ? d?u
        return result;
    } else {
        *returnSize = digitsSize;
        return result + 1; // D?ch k?t qu? l�n m?t � n?u kh�ng c?n th�m ch? s?
    }
}
