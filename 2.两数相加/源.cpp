#include<iostream>
struct ListNode {
    int val;
    struct ListNode* next;
};
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* s = (struct ListNode*)malloc(sizeof(struct ListNode));
    s->next = NULL;
    s->val = (l1->val + l2->val) % 10;
    struct ListNode* L, * r = s;
    int num1 = 0, num2 = 0, a = (l1->val + l2->val) / 10;
    l1 = l1->next;
    l2 = l2->next;
    while (l1 || l2)
    {
        num1 = l1 ? l1->val : 0;  //判断 l1链表下一个节点是否为空，若为空则赋值为0
        num2 = l2 ? l2->val : 0;  //判断 l2链表下一个节点是否为空，若为空则赋值为0
        L = (struct ListNode*)malloc(sizeof(struct ListNode));
        L->val = (num1 + num2 + a) % 10;
        a = (num1 + num2 + a) / 10;
        r->next = L;
        r = L;
        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
    if (a > 0)  //判断是否溢出，若溢出则需要增加一个节点
    {
        L = (struct ListNode*)malloc(sizeof(struct ListNode));
        L->val = a;
        r->next = L;
        r = L;
    }
    r->next = NULL;
    return s;
}