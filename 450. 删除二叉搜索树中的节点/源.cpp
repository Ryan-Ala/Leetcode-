/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	bool _ereaseR(TreeNode*& root, int& key)
	{
		if (!root)return 0;
		if (root->val > key)
			return _ereaseR(root->left, key);
		else if (root->val < key)
			return _ereaseR(root->right, key);
		else
		{
			TreeNode* tmp = root;
			if (!root->left)
			{
				root = root->right;
			}
			else if (!root->right)
			{
				root = root->left;
			}
			else
			{
				TreeNode* ret = root->right, * ret_parent = root;
				while (ret->left)
				{
					ret_parent = ret;
					ret = ret->left;
				}
				swap(ret->val, root->val);
				tmp = ret;
				if (ret == root->right)
					return _ereaseR(root->right, key);   //不能用引用传递ret，因为传递ret，相当于是ret的别名，并不会修改双亲节点的孩子
				else
					return _ereaseR(ret_parent->left, key);
			}
			delete tmp;
			return true;
		}
	}
	TreeNode* deleteNode(TreeNode* root, int key) {
		if (!root)
			return root;
		_ereaseR(root, key);
		return root;
	}
};