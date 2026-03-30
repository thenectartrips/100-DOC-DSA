#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure
struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

// Push
void push(int x)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

// Pop
int pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    struct node *temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int main()
{
    char exp[100];
    int i = 0;

    printf("Enter postfix expression: ");
    fgets(exp, 100, stdin);

    while (exp[i] != '\0')
    {

        // If digit
        if (isdigit(exp[i]))
        {
            push(exp[i] - '0');
        }

        // If operator
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            int b = pop();
            int a = pop();
            int res;

            if (exp[i] == '+')
                res = a + b;
            else if (exp[i] == '-')
                res = a - b;
            else if (exp[i] == '*')
                res = a * b;
            else if (exp[i] == '/')
                res = a / b;

            push(res);
        }

        i++;
    }

    printf("Result = %d\n", pop());

    return 0;
}