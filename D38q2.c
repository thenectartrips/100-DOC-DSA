#include <stdio.h>
#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    
    if (numsSize == 0 || k == 0) {
        *returnSize = 0;
        return NULL;
    }

    int *result = (int*)malloc((numsSize - k + 1) * sizeof(int));
    int *deque = (int*)malloc(numsSize * sizeof(int));

    int front = 0, rear = 0;

    for (int i = 0; i < numsSize; i++) {

        // Remove indices out of window
        if (front < rear && deque[front] <= i - k)
            front++;

        // Remove smaller elements from rear
        while (front < rear && nums[deque[rear - 1]] < nums[i])
            rear--;

        // Add current index
        deque[rear++] = i;

        // Store result when window is ready
        if (i >= k - 1)
            result[i - k + 1] = nums[deque[front]];
    }

    *returnSize = numsSize - k + 1;

    free(deque);
    return result;
}
