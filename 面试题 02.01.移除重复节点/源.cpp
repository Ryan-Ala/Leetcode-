#include<iostream>
struct ListNode {
    int val;
    struct ListNode* next;
};
struct ListNode* removeDuplicateNodes(struct ListNode* head) {
    struct ListNode* ob = head, * m = NULL;
    while (ob)
    {
        m = ob;
        while (m->next)
        {
            if (m->next->val == ob->val)
            {
                struct ListNode* a = m->next;
                m->next = m->next->next;
                free(a);
            }
            else
                m = m->next;
        }
        ob = ob->next;
    }
    return head;
}