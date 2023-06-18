#include<iostream>

struct ListNode {
    int val;
    struct ListNode* next;
};
struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* slow = head, * fast = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            struct ListNode* meet = slow;
            while (meet)
            {
                if (meet == head)
                    return meet;
                head = head->next;
                meet = meet->next;
            }
        }
    }
    return NULL;
}
