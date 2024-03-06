#include<uthash.h>

//哈希表
struct ListNode {
    int val;
    struct ListNode* next;
};
  struct Hash
{
    struct ListNode* val;
    UT_hash_handle hh;
};

struct Hash {
    struct ListNode* val;
    UT_hash_handle hh;
};
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    struct Hash* HashTable = NULL, * p = NULL;
    struct ListNode* temp = headA;
    while (temp)
    {                  //HASH_FIND 函数需要传键值的指针    //p是哈希结构
        HASH_FIND(hh, HashTable, &temp, sizeof(struct Hash*), p);  //寻找
        if (!p)
        {
            p = (struct Hash*)malloc(sizeof(struct Hash));
            p->val = temp;
            HASH_ADD(hh, HashTable, val, sizeof(struct Hash*), p);
        }
        temp = temp->next;
    }
    temp = headB;
    while (temp)
    {
        HASH_FIND(hh, HashTable, &temp, sizeof(struct Hash*), p);
        if (p)
            return temp;
        temp = temp->next;
    }
    return NULL;
}


//快慢指针
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    int length_A = 0, length_B = 0;
    struct ListNode* A = headA, * B = headB;
    while (A)
    {
        A = A->next;
        length_A++;
    }
    while (B)
    {
        B = B->next;
        length_B++;
    }
    A = headA;
    B = headB;
    if (length_A > length_B)
    {
        length_A -= length_B;
        while (length_A--)
        {
            A = A->next;
        }
    }
    else
    {
        length_B -= length_A;
        while (length_B--)
        {
            B = B->next;
        }
    }
    while (A && B)
    {
        if (A == B)
            return A;
        A = A->next;
        B = B->next;
    }
    return NULL;
}