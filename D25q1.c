#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    int n, i, value, key, count = 0;
    struct node *head = NULL, *temp = NULL, *newnode = NULL;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the elements of the linked list:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);

        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = value;
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

    printf("Enter the element to be counted: ");
    scanf("%d", &key);

    temp = head;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            count++;
        }
        temp = temp->next;
    }

    printf("The number of times %d appears in the linked list is: %d\n", key, count);

    return 0;
}