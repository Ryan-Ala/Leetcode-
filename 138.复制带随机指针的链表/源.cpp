#include<iostream>

struct Node {
    int val;
    struct Node* next;
    struct Node* random;
};

struct Node* copyRandomList(struct Node* head)
{
    if (!head) { return NULL; }
    struct Node* ret = (struct Node*)malloc(sizeof(struct Node)), * start = head, * copy = NULL;
    while (start)
    {
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->val = start->val;
        newnode->next = start->next;
        start->next = newnode;
        start = newnode->next;
    }
    start = head;
    while (start)
    {
        copy = start->next;
        if (start->random)
        {
            copy->random = start->random->next;
        }
        else
        {
            copy->random = NULL;
        }
        start = copy->next;
    }
    start = head;
    head = ret;
    while (start)
    {
        copy = start->next;
        ret->next = copy;
        ret = ret->next;
        start->next = copy->next;
        start = start->next;
    }
    copy = head->next;
    free(head);
    return copy;
}