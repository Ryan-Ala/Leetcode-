/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* ret_1 = new ListNode(), * p1 = ret_1;
        ListNode* ret_2 = new ListNode(), * p2 = ret_2, * pos = head;
        int count = 1;
        while (pos)
        {
            if (count % 2)
            {
                p1->next = pos;
                p1 = p1->next;
            }
            else
            {
                p2->next = pos;
                p2 = p2->next;
            }
            count++;
            pos = pos->next;
        }
        p2->next = nullptr;
        p1->next = ret_2->next;
        pos = ret_1->next;
        delete ret_1;
        delete ret_2;
        return pos;
    }
};