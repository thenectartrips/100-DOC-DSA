#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createList(int n)
{
    struct node *head = NULL, *temp = NULL, *newnode;
    int i, value;

    printf("Enter %d elements:\n", n);

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
    return head;
}

struct node *mergeLists(struct node *head1, struct node *head2)
{
    struct node *result = NULL, *temp = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->next = NULL;

        if (head1->data < head2->data)
        {
            newnode->data = head1->data;
            head1 = head1->next;
        }
        else
        {
            newnode->data = head2->data;
            head2 = head2->next;
        }

        if (result == NULL)
        {
            result = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    while (head1 != NULL)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = head1->data;
        newnode->next = NULL;

        if (result == NULL)
        {
            result = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }

        head1 = head1->next;
    }

    while (head2 != NULL)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = head2->data;
        newnode->next = NULL;

        if (result == NULL)
        {
            result = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }

        head2 = head2->next;
    }

    return result;
}

void printList(struct node *head)
{
    printf("Merged Linked List: ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    int n, m;

    printf("Enter number of elements in first list: ");
    scanf("%d", &n);
    struct node *head1 = createList(n);

    printf("Enter number of elements in second list: ");
    scanf("%d", &m);
    struct node *head2 = createList(m);

    struct node *merged = mergeLists(head1, head2);

    printList(merged);

    return 0;
}