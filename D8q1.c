#include <stdio.h>

int power(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    else
    {
        return a * power(a, b - 1);
    }
}

int main()
{
    int a, b;
    int result;

    printf("Enter two numbers (a and b): ");
    scanf("%d %d", &a, &b);

    result = power(a, b);

    printf("%d raised to power %d is %d\n", a, b, result);

    return 0;
}
