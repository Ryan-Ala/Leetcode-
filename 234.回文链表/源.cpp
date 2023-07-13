
struct ListNode {
    int val;
    struct ListNode* next;
};
bool isPalindrome(struct ListNode* head) {
    int ret[100001] = { 0 };
    struct ListNode* p = head;
    int count = 0, k = 0;
    while (p)
    {
        ret[k++] = p->val;
        p = p->next;
        count++;
    }
    int i = 0;
    while (i <= count)
    {
        if (ret[i] != ret[count - 1])
        {
            return 0;
        }
        i++;
        count--;
    }
    return 1;
}