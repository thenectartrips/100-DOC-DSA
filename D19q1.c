#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int min_sum = abs(arr[0] + arr[1]);
    int num1 = arr[0];
    int num2 = arr[1];

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            int sum = arr[i] + arr[j];

            if (abs(sum) < min_sum)
            {
                min_sum = abs(sum);
                num1 = arr[i];
                num2 = arr[j];
            }
        }
    }

    printf("The pair whose sum is closest to zero is: %d %d\n", num1, num2);

    return 0;
}