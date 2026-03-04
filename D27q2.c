#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insertEnd(struct node **head, int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

int detectAndRemoveLoop(struct node *head)
{
    struct node *slow = head;
    struct node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            slow = head;

            while (slow->next != fast->next)
            {
                slow = slow->next;
                fast = fast->next;
            }

            fast->next = NULL;
            return 1;
        }
    }

    return 0;
}

void printList(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    struct node *head = NULL;
    int n, i, value, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    printf("Enter position to create loop (0 for no loop): ");
    scanf("%d", &pos);

    if (pos > 0)
    {
        struct node *temp = head;
        struct node *loopNode = NULL;
        int count = 1;

        while (temp->next != NULL)
        {
            if (count == pos)
                loopNode = temp;
            temp = temp->next;
            count++;
        }
        temp->next = loopNode;
    }

    if (detectAndRemoveLoop(head))
        printf("Loop detected and removed.\n");
    else
        printf("No loop found.\n");

    printf("Linked list after removal: ");
    printList(head);

    return 0;
}