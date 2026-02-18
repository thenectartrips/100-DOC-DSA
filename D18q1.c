#include <stdio.h>

int main()
{
    int n, k, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], temp[n];

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter value of k: ");
    scanf("%d", &k);

    k = k % n;

    for (i = 0; i < n; i++)
    {
        temp[(i + k) % n] = arr[i];
    }

    printf("Rotated array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", temp[i]);
    }

    return 0;
}
