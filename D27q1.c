#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createList(int n)
{
    struct node *head = NULL, *temp = NULL, *newNode;
    int value, i;

    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);

        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head;
}

int length(struct node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

int main()
{
    int n, m, len1, len2, diff;

    printf("Enter number of nodes in first list: ");
    scanf("%d", &n);
    printf("Enter elements of first list: ");
    struct node *head1 = createList(n);

    printf("Enter number of nodes in second list: ");
    scanf("%d", &m);
    printf("Enter elements of second list: ");
    struct node *head2 = createList(m);

    len1 = length(head1);
    len2 = length(head2);

    struct node *ptr1 = head1;
    struct node *ptr2 = head2;

    if (len1 > len2)
    {
        diff = len1 - len2;
        while (diff--)
            ptr1 = ptr1->next;
    }
    else
    {
        diff = len2 - len1;
        while (diff--)
            ptr2 = ptr2->next;
    }

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->data == ptr2->data)
        {
            printf("Intersection found at node with value: %d", ptr1->data);
            return 0;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    printf("No Intersection found.");

    return 0;
}