#include<iostream>
struct ListNode {
    int val;
    struct ListNode* next;
};
 
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;
    struct ListNode* m = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* a = list1, * b = list2, * n = m;
    while (1)
    {
        if (a == NULL)
        {
            m->next = b;
            break;
        }
        if (b == NULL)
        {
            m->next = a;
            break;
        }
        if (a->val < b->val)
        {
            m->next = a;
            a = a->next;
        }
        else
        {
            m->next = b;
            b = b->next;
        }
        m = m->next;
    }
    return n->next;
}
