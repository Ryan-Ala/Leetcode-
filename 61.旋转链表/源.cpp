#include<iostream>
struct ListNode
{
    int val;
    struct ListNode* next;
};
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (k == 0 || !head || !head->next) { return head; }
    int count = 1;
    struct ListNode* p = head;
    while (p->next)
    {
        p = p->next;
        count++;
    }
    if (k % count == 0) { return head; }
    k %= count;
    struct ListNode* s = head;
    count = count - k - 1;
    while (count--)
    {
        s = s->next;
    }
    p->next = head;
    head = s->next;
    s->next = NULL;
    return head;
}