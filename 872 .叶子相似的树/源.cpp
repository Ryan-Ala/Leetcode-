struct TreeNode {
    *int val;
    *struct TreeNode* left;
    *struct TreeNode* right;
    *
};
*/

void prev(struct TreeNode* root, int* count, int* ret)
{
    if (!root)
        return;
    if (!root->left && !root->right)
        ret[(*count)++] = root->val;
    prev(root->left, count, ret);
    prev(root->right, count, ret);
}
bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    int numsize1 = 0, numsize2 = 0;
    int* ret1 = (int*)malloc(sizeof(int) * 100), * ret2 = (int*)malloc(sizeof(int) * 100);
    prev(root1, &numsize1, ret1);
    prev(root2, &numsize2, ret2);
    if (numsize1 == numsize2)
    {

        while (numsize1--)
        {
            if (ret1[numsize1] != ret2[numsize1])
                break;
        }
        if (numsize1 == -1)
        {
            free(ret1);
            free(ret2);
            return 1;
        }
    }
    free(ret1);
    free(ret2);
    return 0;
}