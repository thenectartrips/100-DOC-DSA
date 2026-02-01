#include <stdio.h>

int main()
{
    int n;
    int a[100];
    int pos;
    int x;
    int i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    printf("Enter element to insert: ");
    scanf("%d", &x);

    for(i = n; i >= pos; i--)
    {
        a[i] = a[i - 1];
    }

    a[pos - 1] = x;

    printf("Updated array:\n");
    for(i = 0; i <= n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
