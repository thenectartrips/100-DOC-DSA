#include <stdio.h>

#define MAX 100 // Maximum size for queue and stack

int main()
{
    int queue[MAX], stack[MAX];
    int n, i;
    int front = 0, rear = -1; // Queue pointers
    int top = -1;             // Stack pointer

    // Ask user for number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input queue elements
    printf("Enter %d elements in queue: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &queue[i]);
        rear++;
    }

    // Move queue elements into stack
    while (front <= rear)
    {
        top++;
        stack[top] = queue[front];
        front++;
    }

    // Reset queue pointers
    front = 0;
    rear = -1;

    // Move stack elements back into queue (reversed)
    while (top >= 0)
    {
        rear++;
        queue[rear] = stack[top];
        top--;
    }

    // Print reversed queue
    printf("Reversed Queue is: ");
    for (i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    return 0;
}