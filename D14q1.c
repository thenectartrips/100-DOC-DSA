#include <stdio.h>

int main()
{
    int n, i, j;
    int matrix[10][10];
    int isIdentity = 1;

    printf("Enter size of square matrix: ");
    scanf("%d", &n);

    printf("Enter matrix elements:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                if (matrix[i][j] != 1)
                {
                    isIdentity = 0;
                }
            }
            else
            {
                if (matrix[i][j] != 0)
                {
                    isIdentity = 0;
                }
            }
        }
    }

    if (isIdentity == 1)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}
