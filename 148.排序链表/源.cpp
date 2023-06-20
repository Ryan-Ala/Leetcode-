#include<iostream>
struct ListNode {
    int val;
    struct ListNode* next;
};
int cmp(const void* a, const void* b)
{
    return *(int*)a > *(int*)b;
}
struct ListNode* sortList(struct ListNode* head) {
    int ret[50000];
    struct ListNode* start = head;
    int i = 0;
    while (start)
    {
        ret[i++] = start->val;
        start = start->next;
    }
    qsort(ret, i, sizeof(int), cmp);
    start = head;
    i = 0;
    while (start)
    {
        start->val = ret[i++];
        start = start->next;
    }
    return head;
}