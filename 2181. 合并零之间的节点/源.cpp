class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans = new ListNode(), * ptr = ans;
        ListNode* fast = head, * slow = head;
        int sum = 0;
        while (fast)
        {
            while (fast && fast->val != 0)
                fast = fast->next;
            slow = fast->next;
            while (slow && slow->val != 0)
            {
                sum += slow->val;
                slow = slow->next;
            }
            if (sum)
            {
                ListNode* new_node = new ListNode(sum);
                ptr->next = new_node;
                ptr = ptr->next;
            }
            sum = 0;
            fast = slow;
        }
        return ans->next;
    }
};