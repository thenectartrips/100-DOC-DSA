#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *heap;
    int size;
    int capacity;
    int k;
} KthLargest;

// Swap helper
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Heapify up
void heapifyUp(KthLargest* obj, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (obj->heap[parent] > obj->heap[i]) {
            swap(&obj->heap[parent], &obj->heap[i]);
            i = parent;
        } else break;
    }
}

// Heapify down
void heapifyDown(KthLargest* obj, int i) {
    while (1) {
        int smallest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < obj->size && obj->heap[left] < obj->heap[smallest])
            smallest = left;
        if (right < obj->size && obj->heap[right] < obj->heap[smallest])
            smallest = right;

        if (smallest != i) {
            swap(&obj->heap[i], &obj->heap[smallest]);
            i = smallest;
        } else break;
    }
}

// Insert into heap
void insert(KthLargest* obj, int val) {
    obj->heap[obj->size++] = val;
    heapifyUp(obj, obj->size - 1);
}

// Remove top (min)
void removeMin(KthLargest* obj) {
    obj->heap[0] = obj->heap[obj->size - 1];
    obj->size--;
    heapifyDown(obj, 0);
}

// Create object
KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->heap = (int*)malloc(sizeof(int) * k);
    obj->size = 0;
    obj->capacity = k;
    obj->k = k;

    for (int i = 0; i < numsSize; i++) {
        if (obj->size < k) {
            insert(obj, nums[i]);
        } else if (nums[i] > obj->heap[0]) {
            removeMin(obj);
            insert(obj, nums[i]);
        }
    }

    return obj;
}

// Add function
int kthLargestAdd(KthLargest* obj, int val) {
    if (obj->size < obj->k) {
        insert(obj, val);
    } else if (val > obj->heap[0]) {
        removeMin(obj);
        insert(obj, val);
    }

    return obj->heap[0];
}

// Free memory
void kthLargestFree(KthLargest* obj) {
    free(obj->heap);
    free(obj);
}
