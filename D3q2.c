int missingNum(int *arr, int size) {
    long long expectedSum, actualSum = 0;
    int n = size + 1;

    // Sum of array elements
    for (int i = 0; i < size; i++) {
        actualSum += arr[i];
    }

    // Sum from 1 to n
    expectedSum = (long long)n * (n + 1) / 2;

    return (int)(expectedSum - actualSum);
}
