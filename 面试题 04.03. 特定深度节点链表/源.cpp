/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode(int x) : val(x), next(NULL) {}
  * };
  */
class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        int left = 0, right = 0, tmp;
        vector<ListNode*> ans;
        vector<TreeNode*> res;
        res.push_back(tree);
        right++;
        while (left != right)
        {
            tmp = left;
            left = right;
            ListNode* cur = new ListNode(), * pos = cur;
            for (int i = tmp; i < left; i++)
            {
                ListNode* new_node = new ListNode(res[i]->val);
                pos->next = new_node;
                pos = pos->next;
                if (res[i]->left)
                {
                    res.push_back(res[i]->left);
                    right++;
                }
                if (res[i]->right)
                {
                    res.push_back(res[i]->right);
                    right++;
                }
            }
            ans.push_back(cur->next);
            delete cur;

        }
        return ans;

    }
};