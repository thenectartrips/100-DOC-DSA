#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create(int n)
{
    struct node *head = NULL, *temp, *newnode;
    int val;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);

        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = val;
        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

void rotateRight(struct node **head, int k, int n)
{
    if (*head == NULL || k == 0)
        return;

    struct node *temp = *head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = *head;

    int steps = n - (k % n);
    for (int i = 0; i < steps - 1; i++)
    {
        *head = (*head)->next;
    }

    struct node *newHead = (*head)->next;
    (*head)->next = NULL;

    *head = newHead;
}

void display(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    int n, k;

    scanf("%d", &n);

    struct node *head = create(n);

    scanf("%d", &k);

    rotateRight(&head, k, n);

    display(head);

    return 0;
}