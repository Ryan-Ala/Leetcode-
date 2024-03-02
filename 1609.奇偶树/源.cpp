#include<iostream>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;

};



bool isEvenOddTree(struct TreeNode* root) {
    struct TreeNode* ret[100000];
    int left = 0, right = 0, temp = 0, hight = 0;
    ret[right++] = root;
    while (left != right)
    {
        temp = right;
        for (int i = 0; i < temp - left; i++)
        {
            if (ret[left + i]->left)
                ret[right++] = ret[left + i]->left;
            if (ret[left + i]->right)
                ret[right++] = ret[left + i]->right;
        }
        if (hight % 2 == 0)
        {
            for (int i = 0; i < temp - left - 1; i++)
            {
                if ((ret[left + i]->val % 2 == 0) || ret[left + i]->val >= ret[left + i + 1]->val)
                    return 0;
            }
            if (ret[temp - 1]->val % 2 == 0)
                return 0;
        }
        else
        {
            for (int i = 0; i < temp - left - 1; i++)
            {
                if ((ret[left + i]->val % 2 == 1) || ret[left + i]->val <= ret[left + i + 1]->val)
                    return 0;
            }
            if (ret[temp - 1]->val % 2 == 1)
                return 0;
        }
        left = temp;
        hight++;
    }
    return 1;
}

bool prev(struct TreeNode* root, int* ret, int height)
{
    if (!root)
        return 1;
    if (height % 2 == 0)
    {
        if (root->val % 2 == 1 && ret[height] < root->val)
            ret[height] = root->val;
        else
            return 0;
    }
    else
    {
        if (root->val % 2 == 0 && ret[height] > root->val)
            ret[height] = root->val;
        else
            return 0;
    }
    return prev(root->left, ret, height + 1) && prev(root->right, ret, height + 1);
}

bool isEvenOddTree(struct TreeNode* root) {
    int ret[100000];
    for (int i = 0; i < 100000; i += 2)
        ret[i] = 0;
    for (int i = 1; i < 100000; i += 2)
        ret[i] = INT_MAX;
    return prev(root, ret, 0);
}