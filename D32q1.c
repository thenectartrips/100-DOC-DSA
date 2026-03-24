#include <stdio.h>

int main()
{
    int stack[100];
    int n, m;
    int top = -1;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }

    printf("Enter number of pops: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++)
    {
        if (top == -1)
        {
            printf("Stack Underflow\n");
            break;
        }
        top--;
    }

    printf("Remaining stack:\n");
    for (int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }

    return 0;
}