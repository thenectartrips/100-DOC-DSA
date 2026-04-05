#include <stdlib.h>

typedef struct {
    int num;
    int freq;
} Pair;

int cmp(const void *a, const void *b) {
    Pair *x = (Pair *)a;
    Pair *y = (Pair *)b;
    return y->freq - x->freq;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    Pair arr[numsSize];
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        int found = 0;
        for (int j = 0; j < count; j++) {
            if (arr[j].num == nums[i]) {
                arr[j].freq++;
                found = 1;
                break;
            }
        }
        if (!found) {
            arr[count].num = nums[i];
            arr[count].freq = 1;
            count++;
        }
    }

    qsort(arr, count, sizeof(Pair), cmp);

    int *result = (int *)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        result[i] = arr[i].num;
    }

    *returnSize = k;
    return result;
}
