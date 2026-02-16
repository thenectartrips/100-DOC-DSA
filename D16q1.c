#include <stdio.h>

int main()
{
    int n, i, j;
    int a[100];
    int count;

    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++)
    {
        count = 1;

        if (a[i] == -1)
            continue;

        for (j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                count++;
                a[j] = -1;
            }
        }

        printf("%d:%d ", a[i], count);
    }

    return 0;
}
