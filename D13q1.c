#include <stdio.h>

int main()
{
    int a[100][100];
    int r, c;
    int top, bottom, left, right;
    int i;

    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter matrix elements:\n");
    for (i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    top = 0;
    bottom = r - 1;
    left = 0;
    right = c - 1;

    printf("Spiral Traversal: ");

    while (top <= bottom && left <= right)
    {

        for (i = left; i <= right; i++)
        {
            printf("%d ", a[top][i]);
        }
        top++;

        for (i = top; i <= bottom; i++)
        {
            printf("%d ", a[i][right]);
        }
        right--;

        if (top <= bottom)
        {
            for (i = right; i >= left; i--)
            {
                printf("%d ", a[bottom][i]);
            }
            bottom--;
        }

        if (left <= right)
        {
            for (i = bottom; i >= top; i--)
            {
                printf("%d ", a[i][left]);
            }
            left++;
        }
    }

    return 0;
}
