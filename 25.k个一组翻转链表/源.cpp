#include<iostream>
struct ListNode {
    int val;
   struct ListNode* next;
    
};
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* ret[5000], * p = head;
    int i = 0, left, right;
    for (i; p; i++)
    {
        ret[i] = p;
        p = p->next;
    }
    for (int j = 0; j <= i - k; j += k)
    {
        left = j;
        right = j + k - 1;
        while (left < right)
        {
            p = ret[right];
            ret[right--] = ret[left];
            ret[left++] = p;
        }
    }
    for (int j = 0; j < i - 1; j++)
    {
        ret[j]->next = ret[j + 1];
    }
    ret[i - 1]->next = NULL;
    return ret[0];
}