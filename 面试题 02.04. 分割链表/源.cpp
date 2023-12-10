
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* ret1 = new ListNode(), * pos1 = ret1;
        ListNode* ret2 = new ListNode(), * pos2 = ret2, * pos = head;
        while (pos)
        {
            if (pos->val < x)
            {
                pos1->next = pos;
                pos1 = pos1->next;
            }
            else
            {
                pos2->next = pos;
                pos2 = pos2->next;
            }
            pos = pos->next;
        }
        pos1->next = ret2->next;
        pos2->next = NULL;
        pos1 = ret1->next;
        delete ret1;
        delete ret2;
        return pos1;
    }
};