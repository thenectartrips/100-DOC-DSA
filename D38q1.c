#include <stdio.h>
#include <string.h>

#define MAX 100

int arr[MAX];
int front = -1, rear = -1, count = 0;

int isEmpty()
{
    return count == 0;
}

int isFull()
{
    return count == MAX;
}

void push_front(int x)
{
    if (isFull())
    {
        printf("Deque is full\n");
        return;
    }

    if (isEmpty())
    {
        front = rear = 0;
    }
    else if (front == 0)
    {
        front = MAX - 1;
    }
    else
    {
        front--;
    }

    arr[front] = x;
    count++;
}

void push_back(int x)
{
    if (isFull())
    {
        printf("Deque is full\n");
        return;
    }

    if (isEmpty())
    {
        front = rear = 0;
    }
    else if (rear == MAX - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    arr[rear] = x;
    count++;
}

void pop_front()
{
    if (isEmpty())
    {
        printf("-1\n");
        return;
    }

    printf("%d\n", arr[front]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == MAX - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }

    count--;
}

void pop_back()
{
    if (isEmpty())
    {
        printf("-1\n");
        return;
    }

    printf("%d\n", arr[rear]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else if (rear == 0)
    {
        rear = MAX - 1;
    }
    else
    {
        rear--;
    }

    count--;
}

void get_front()
{
    if (isEmpty())
        printf("-1\n");
    else
        printf("%d\n", arr[front]);
}

void get_back()
{
    if (isEmpty())
        printf("-1\n");
    else
        printf("%d\n", arr[rear]);
}

void size()
{
    printf("%d\n", count);
}

void empty()
{
    if (isEmpty())
        printf("True\n");
    else
        printf("False\n");
}

void clear()
{
    front = rear = -1;
    count = 0;
}

void display()
{
    if (isEmpty())
    {
        printf("Deque is empty\n");
        return;
    }

    int i = front;
    while (1)
    {
        printf("%d ", arr[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);

    while (n--)
    {
        char op[20];
        scanf("%s", op);

        if (strcmp(op, "push_front") == 0)
        {
            int x;
            scanf("%d", &x);
            push_front(x);
        }
        else if (strcmp(op, "push_back") == 0)
        {
            int x;
            scanf("%d", &x);
            push_back(x);
        }
        else if (strcmp(op, "pop_front") == 0)
        {
            pop_front();
        }
        else if (strcmp(op, "pop_back") == 0)
        {
            pop_back();
        }
        else if (strcmp(op, "front") == 0)
        {
            get_front();
        }
        else if (strcmp(op, "back") == 0)
        {
            get_back();
        }
        else if (strcmp(op, "size") == 0)
        {
            size();
        }
        else if (strcmp(op, "empty") == 0)
        {
            empty();
        }
        else if (strcmp(op, "clear") == 0)
        {
            clear();
        }
        else if (strcmp(op, "display") == 0)
        {
            display();
        }
    }

    return 0;
}