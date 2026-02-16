#include <stdio.h>

int main()
{
    int m, n;
    int a[10][10];
    int i, j;
    int sum = 0;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    printf("Enter matrix elements:\n");

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    if (m != n)
    {
        printf("Primary diagonal exists only for square matrix.\n");
    }
    else
    {
        for (i = 0; i < m; i++)
        {
            sum = sum + a[i][i];
        }

        printf("Sum of primary diagonal elements = %d", sum);
    }

    return 0;
}
