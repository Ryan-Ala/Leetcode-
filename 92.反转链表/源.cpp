#include<iostream>
struct ListNode {
    int val;
    struct ListNode* next;
};
struct ListNode* reverseList(struct ListNode* head, struct ListNode** end) {
    if (!head->next->next)
    {
        struct ListNode* s = head->next;
        s->next = head;
        head->next = NULL;
        *end = head;
        return s;
    }
    struct ListNode* p = head->next, * s = NULL, * a = head;
    while (p)
    {
        head->next = s;
        s = head;
        head = p;
        p = p->next;
    }
    head->next = s;
    *end = a;
    return head;

}
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (left == right) { return head; }
    int count = 1;
    struct ListNode* first = (struct ListNode*)malloc(sizeof(struct ListNode));
    first->next = head;
    struct ListNode* start = head, * prev = first, * rear = NULL, * end = NULL, * a = NULL;
    while (count < left)
    {
        prev = prev->next;
        start = start->next;
        count++;
    }
    end = start;
    while (count < right)
    {
        end = end->next;
        count++;
    }
    rear = end->next;
    end->next = NULL;
    prev->next = reverseList(start, &a);
    a->next = rear;
    return first->next;
}
