#include<iostream>
#include<uthash.h>
struct ListNode {
    int val;
    struct ListNode* next;
};
struct Hash
{
    struct ListNode* val;
    UT_hash_handle hh;
};

struct ListNode* detectCycle(struct ListNode* head) {
    struct Hash* hash = NULL, * temp = NULL;
    struct ListNode* p = head;
    while (p)
    {
        HASH_FIND(hh, hash, &p, sizeof(struct Hash*), temp);
        if (!temp)
        {
            temp = (struct Hash*)malloc(sizeof(struct Hash));
            temp->val = p;
            HASH_ADD(hh, hash, val, sizeof(struct Hash*), temp);
        }
        else
            return p;
        p = p->next;
    }
    return NULL;
}