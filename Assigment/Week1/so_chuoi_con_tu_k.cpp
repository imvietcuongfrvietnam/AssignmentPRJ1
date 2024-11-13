#include <stdio.h>

long count_even_k_subsequences(long arr[], long n, long k) {
    long even_count = 0;
    long odd_count = 0;
    long current_sum = 0;

    // Calculate the sum of the first k elements
    for (long i = 0; i < k; i++) {
        current_sum += arr[i];
    }

    // Check if the first k-sum is even
    if (current_sum % 2 == 0) {
        even_count++;
    } else {
        odd_count++;
    }

    // Sliding window to check other k-subsequences
    for (long i = k; i < n; i++) {
        current_sum += arr[i];        // Add the new element
        current_sum -= arr[i - k];    // Remove the element that is now out of the window

        // Check if the current sum is even
        if (current_sum % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    return even_count; // Return the number of even k-subsequences
}

int main() {
    long n, k;
    scanf("%ld %ld", &n, &k);
    long arr[n]; // Define the array of size n

    // Read the elements of the array
    for (long i = 0; i < n; i++) {
        scanf("%ld", &arr[i]);
    }

    // Get the count of even k-subsequences
    long result = count_even_k_subsequences(arr, n, k);
    printf("%ld\n", result);

    return 0;
}

