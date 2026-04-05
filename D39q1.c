#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

// Swap function
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up (for insert)
void heapifyUp(int index)
{
    while (index > 0 && heap[(index - 1) / 2] > heap[index])
    {
        swap(&heap[(index - 1) / 2], &heap[index]);
        index = (index - 1) / 2;
    }
}

// Heapify down (for extractMin)
void heapifyDown(int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index)
    {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Insert element
void insert(int x)
{
    if (size == MAX)
        return;

    heap[size] = x;
    heapifyUp(size);
    size++;
}

// Extract minimum
int extractMin()
{
    if (size == 0)
        return -1;

    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);

    return root;
}

// Peek minimum
int peek()
{
    if (size == 0)
        return -1;
    return heap[0];
}

int main()
{
    int n;
    scanf("%d", &n);

    char op[20];
    int x;

    for (int i = 0; i < n; i++)
    {
        scanf("%s", op);

        if (op[0] == 'i')
        { // insert
            scanf("%d", &x);
            insert(x);
        }
        else if (op[0] == 'e')
        { // extractMin
            printf("%d\n", extractMin());
        }
        else if (op[0] == 'p')
        { // peek
            printf("%d\n", peek());
        }
    }

    return 0;
}