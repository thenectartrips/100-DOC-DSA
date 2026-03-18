struct ListNode* reverse(struct ListNode* head)
{
    struct ListNode *prev = NULL;
    struct ListNode *next = NULL;

    while(head != NULL)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    return prev;
}

bool isPalindrome(struct ListNode* head)
{
    if(head == NULL || head->next == NULL)
        return true;

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode *second = reverse(slow->next);
    struct ListNode *first = head;

    while(second != NULL)
    {
        if(first->val != second->val)
            return false;

        first = first->next;
        second = second->next;
    }

    return true;
}
