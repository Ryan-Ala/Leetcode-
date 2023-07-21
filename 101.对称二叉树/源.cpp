
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
bool cmp(struct TreeNode* left, struct TreeNode* right)
{
    if (!left && !right)
        return 1;
    if (!left || !right)
        return 0;
    if (left->val != right->val)
        return 0;
    return cmp(left->left, right->right) && cmp(left->right, right->left);

}
bool isSymmetric(struct TreeNode* root) {
    return cmp(root->left, root->right);
}