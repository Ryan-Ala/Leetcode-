/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
	void dfs(TreeNode* root, TreeNode*& prev)  //prev 是上一个节点
	{
		if (!root) return;

		dfs(root->left, prev);

		if (prev)
			prev->right = root;
		root->left = prev;
		prev = root;

		dfs(root->right, prev);
	}
public:
	TreeNode* Convert(TreeNode* pRootOfTree) {
		if (!pRootOfTree) return pRootOfTree;
		TreeNode* ptr = nullptr, * tmp = pRootOfTree;
		dfs(pRootOfTree, ptr);

		while (tmp->left)
			tmp = tmp->left;

		return tmp;
	}
};
