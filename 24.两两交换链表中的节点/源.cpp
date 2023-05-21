#include<iostream>
struct ListNode {
    int val;
    struct ListNode* next;
};
struct ListNode* swapPairs(struct ListNode* head) {
    if (!head || !head->next) { return head; }
    struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode)), * node2 = (struct ListNode*)malloc(sizeof(struct ListNode)), * node3 = (struct ListNode*)malloc(sizeof(struct ListNode)), * s1 = head, * s2 = head->next, * n1 = node1, * n2 = node2, * n3 = node3;
    while (1)
    {
        n1->next = s1;
        n2->next = s2;
        n1 = n1->next;
        n2 = n2->next;
        if (!s2->next)
        {
            break;
        }
        if (!s2->next->next)
        {
            s1 = s1->next->next;
            n1->next = s1;
            n1 = n1->next;
            break;
        }
        s1 = s1->next->next;
        s2 = s2->next->next;
    }
    n1->next = NULL;
    n2->next = NULL;
    n1 = node1->next;
    n2 = node2->next;
    while (n1 && n2)
    {
        n3->next = n2;
        n2 = n2->next;
        n3 = n3->next;
        n3->next = n1;
        n3 = n3->next;
        n1 = n1->next;
    }
    n3 = node3->next;
    free(node1);
    free(node2);
    free(node3);
    return n3;
}