
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    bool dfs(TreeNode* root, TreeNode* target)
    {
        if (!root) return 0;
        if (root == target) return 1;
        return dfs(root->left, target) || dfs(root->right, target);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q)
            //���������������p��qһ�����������ϵ����ô��ǰ�ڵ����Ҫ�ҵĹ����ڵ㣬���򲻿����������������
            return root;

        bool p_left = 0, p_right = 0, q_left = 0, q_right = 0;
        p_left = dfs(root->left, p);
        if (!p_left) p_right = !p_left;

        q_right = dfs(root->right, q);
        if (!q_right) q_left = !q_right;

        if (q_left && p_left)
            return lowestCommonAncestor(root->left, p, q);
        if (q_right && p_right)
            return lowestCommonAncestor(root->right, p, q);

        //if((q_left&&p_right)||(q_right&&p_left))  
        return root;  //�������㣬ֻ��˵�������࣬��ô��ǰ�Ľڵ���ǹ����ڵ�

    }
};