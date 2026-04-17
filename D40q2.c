#include <stdlib.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    *returnSize = temperaturesSize;
    
    int* result = (int*)malloc(sizeof(int) * temperaturesSize);
    int* stack = (int*)malloc(sizeof(int) * temperaturesSize); // store indices
    
    int top = -1;

    for (int i = 0; i < temperaturesSize; i++) {
        result[i] = 0; // default
    }

    for (int i = 0; i < temperaturesSize; i++) {
        // Pop until current temp is higher
        while (top != -1 && temperatures[i] > temperatures[stack[top]]) {
            int prevIndex = stack[top--];
            result[prevIndex] = i - prevIndex;
        }
        stack[++top] = i;
    }

    free(stack);
    return result;
}
