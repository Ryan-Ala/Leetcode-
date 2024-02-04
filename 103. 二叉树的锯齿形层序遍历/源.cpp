/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


void fun(struct TreeNode** ret, int returnSize, int** res, int height, int temp, int left)
{
    int k = 0;
    if (height % 2)
    {
        for (int i = temp - 1; i >= left; i--)
        {
            res[returnSize][k++] = ret[i]->val;
        }
    }
    else
    {
        for (int i = left; i < temp; i++)
        {
            res[returnSize][k++] = ret[i]->val;
        }
    }

}
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (!root)
        return NULL;
    struct TreeNode* ret[2000];
    int left = 0, right = 0, temp = 0, height = 0;
    (*returnColumnSizes) = (int*)malloc(sizeof(int) * 2000);
    int** res = (int**)malloc(sizeof(int*) * 2000);
    *returnSize = 0;
    ret[right++] = root;
    while (left != right)
    {
        left = temp;
        temp = right;
        (*returnColumnSizes)[(*returnSize)] = temp - left;
        res[(*returnSize)] = (int*)malloc(sizeof(int) * (temp - left));
        fun(ret, (*returnSize)++, res, height, temp, left);
        height++;
        for (int i = 0; i < temp - left; i++)
        {
            if (ret[i + left]->left)
                ret[right++] = ret[left + i]->left;
            if (ret[i + left]->right)
                ret[right++] = ret[left + i]->right;
        }
    }
    (*returnSize)--;
    return res;
    //struct TreeNode*ret[2000]
}