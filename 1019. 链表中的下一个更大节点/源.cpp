class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ret(10000, 0);
        ListNode* pos = head;
        int length = 0, j;
        while (pos)
        {
            ret[length++] = pos->val;
            pos = pos->next;
        }
        vector<int> ans(length, 0);
        int t;
        for (t = 0; t < length - 1; t++)
        {
            if (ret[t] < ret[t + 1])
                break;
        }
        if (t == length - 1)
            return ans;
        for (int i = length - 2; i > -1; i--)
        {
            j = i + 1;
            if (ret[i] < ret[j])
                ans[i] = ret[j];
            else
            {
                while (j < length && ret[i] >= ans[j])
                {
                    j++;
                }
                if (j < length)
                    ans[i] = ans[j];
            }
        }
        return ans;
    }
};