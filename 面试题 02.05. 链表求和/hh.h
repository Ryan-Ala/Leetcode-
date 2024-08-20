struct ListNode {
    int val;
    struct ListNode* next;
    
};


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int count1 = 0, count2 = 0, count = 0;
    struct ListNode* p1 = l1, * p2 = l2, * temp = NULL, * ps = NULL;
    while (p1)
    {
        count1++;
        p1 = p1->next;
    }
    while (p2)
    {
        count2++;
        p2 = p2->next;
    }
    if (count1 >= count2)
    {
        temp = l1;
        p1 = l1;
        p2 = l2;
    }
    else
    {
        temp = l2;
        p1 = l2;
        p2 = l1;
    }
    while (p1 && p2)
    {
        count += p1->val + p2->val;
        p1->val = count % 10;
        count /= 10;
        ps = p1;
        p1 = p1->next;
        p2 = p2->next;
    }
    while (p1)
    {
        count += p1->val;
        p1->val = count % 10;
        count /= 10;
        ps = p1;
        p1 = p1->next;
    }
    if (count != 0)
    {
        ps->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        ps->next->val = count;
        ps->next->next = NULL;
    }
    return temp;
}