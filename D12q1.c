#include <stdio.h>

int main()
{
    int m, n;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    int a[m][n];

    printf("Enter the elements of the matrix:\n");

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    if (m != n)
    {
        printf("The given matrix is Not a Symmetric Matrix");
        return 0;
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != a[j][i])
            {
                printf("The given matrix is Not a Symmetric Matrix");
                return 0;
            }
        }
    }

    printf("The given matrix is a Symmetric Matrix");

    return 0;
}
