
#include<iostream>
struct ListNode {
    int val;
    struct ListNode* next;
};
struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode* p = head->next, * ret = (struct ListNode*)malloc(sizeof(struct ListNode)), * m = ret, * s = NULL;
    ret->next = head;
    head->next = NULL;
    while (p)
    {
        s = p;
        p = p->next;
        m = ret;
        while (m->next && s->val > m->next->val)
            m = m->next;
        s->next = m->next;
        m->next = s;
    }
    p = ret->next;
    free(ret);
    return p;
}

int length(struct ListNode* p)
{
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}
int cmp(const void* a, const void* b)
{
    return ((*(struct ListNode**)a)->val) > ((*(struct ListNode**)b)->val);
}
struct ListNode* insertionSortList1(struct ListNode* head) {
    int leng = length(head);
    struct ListNode** ret = (struct ListNode**)malloc(sizeof(struct ListNode*) * leng);
    struct ListNode* p = head;
    for (int i = 0; i < leng; i++)
    {
        ret[i] = p;
        p = p->next;
    }
    qsort(ret, sizeof(struct ListNode*), leng, cmp);
    for (int i = 0; i < leng - 1; i++)
    {
        ret[i]->next = ret[i + 1];
    }
    ret[leng - 1]->next = NULL;
    p = ret[0];
    free(ret);
    return p;
}