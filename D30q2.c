struct ListNode* makeNode(int x) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = x;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int a[105], b[105];
    int i = 0, j = 0;
    
    while (l1 != NULL) {
        a[i++] = l1->val;
        l1 = l1->next;
    }
    
    while (l2 != NULL) {
        b[j++] = l2->val;
        l2 = l2->next;
    }
    
    int carry = 0;
    struct ListNode* head = NULL;
    
    i--;
    j--;
    
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        
        if (i >= 0) {
            sum += a[i];
            i--;
        }
        
        if (j >= 0) {
            sum += b[j];
            j--;
        }
        
        struct ListNode* newNode = makeNode(sum % 10);
        newNode->next = head;
        head = newNode;
        
        carry = sum / 10;
    }
    
    return head;
}
