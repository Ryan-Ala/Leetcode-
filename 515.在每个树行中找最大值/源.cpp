struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    
};


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
    int* largestValues(struct TreeNode* root, int* returnSize) {
    if (!root)
    {
        *returnSize = 0;
        return NULL;
    }
    struct TreeNode* res[10000], * p = NULL;
    int* ret = (int*)calloc(3000, sizeof(int)), left = 0, right = 0, temp = 0, size = 0, max = 0;
    *returnSize = 0;
    res[right++] = root;
    while (left != right)
    {
        temp = right;
        max = res[left]->val;
        for (int i = 0; i < temp - left; i++)
        {
            if (res[i + left]->val > max)
                max = res[i + left]->val;
            if (res[i + left]->left)
                res[right++] = res[i + left]->left;
            if (res[i + left]->right)
                res[right++] = res[i + left]->right;
        }
        left = temp;
        ret[(*returnSize)++] = max;
    }
    return ret;
}

    int fun(struct TreeNode* root)
    {
        if (!root)
            return 0;
        int count = 0;
        while (root)
        {
            count++;
            root = root->left;
        }
        return count;
    }
    int countNodes(struct TreeNode* root) {

        if (!root)
            return 0;
        int left = fun(root->left);
        int right = fun(root->right);
        if (left == right)   //左子树肯定是满二叉树
        {
            return (1 << left) + countNodes(root->right);
        }
        else
        {
            return (1 << right) + countNodes(root->left);
        }
        return 0;
    }