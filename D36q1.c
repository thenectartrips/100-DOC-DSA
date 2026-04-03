#include <stdio.h>

#define SIZE 100

int queue[SIZE];
int front = 0, rear = 0;

void enqueue(int x)
{
    queue[rear] = x;
    rear = (rear + 1) % SIZE;
}

void dequeue()
{
    if (front == rear)
    {
        return; // queue empty
    }
    front = (front + 1) % SIZE;
}

void display()
{
    int i = front;
    while (i != rear)
    {
        printf("%d ", queue[i]);
        i = (i + 1) % SIZE;
    }
}

int main()
{
    int n, m, i, x;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    for (i = 0; i < m; i++)
    {
        dequeue();
    }

    display();

    return 0;
}