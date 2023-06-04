
#include<iostream>
struct ListNode {
    int val;
    struct ListNode* next;
};
struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2) {
    int num = 0;
    struct ListNode* start = list1, * Free = NULL;
    while (start && num + 1 != a)
    {
        start = start->next;
        num++;
    }
    Free = start->next;
    start->next = list2;
    start = Free;
    while (a != b + 1)
    {
        a++;
        start = start->next;
        free(Free);
        Free = start;
    }
    while (list2->next)
    {
        list2 = list2->next;
    }
    list2->next = start;
    return list1;
}