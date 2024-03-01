int prev(struct TreeNode* root)
{
    if (!root)
        return 0;
    return fmax(prev(root->left), prev(root->right)) + 1;
}

bool isBalanced(struct TreeNode* root) {
    if (!root)
        return 1;
    return abs(prev(root->left) - prev(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);

}