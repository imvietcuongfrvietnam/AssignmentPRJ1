int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *result = (int*)malloc(sizeof(int) * (digitsSize + 1));
    int c = 1;  // Giá tr? carry ban d?u là 1 vì c?ng thêm 1 vào s?

    // Tính toán t? ch? s? cu?i cùng d?n ch? s? d?u tiên
    for (int i = digitsSize - 1; i >= 0; i--) {
        result[i + 1] = (digits[i] + c) % 10;
        c = (digits[i] + c) / 10;
    }

    // N?u còn carry sau khi l?p
    if (c == 1) {
        result[0] = 1;
        *returnSize = digitsSize + 1; // C?n thêm m?t ch? s? ? d?u
        return result;
    } else {
        *returnSize = digitsSize;
        return result + 1; // D?ch k?t qu? lên m?t ô n?u không c?n thêm ch? s?
    }
}
