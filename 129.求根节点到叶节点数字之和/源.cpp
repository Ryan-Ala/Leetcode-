#include<iostream>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int prev(struct TreeNode* root, int val)
{
    if (!root)
        return 0;
    val = val * 10 + root->val;
    if (!root->left && !root->right)
        return val;
    return prev(root->left, val) + prev(root->right, val);
}
int sumNumbers(struct TreeNode* root) {
    return prev(root, 0);
}

 int sumNumbers(struct TreeNode* root){
    struct TreeNode*ret[1000];
    int left=0,right=0,temp=0,sum=0;
    ret[right++]=root;
    while(left!=right)
    {
        temp=right;
        for(int i=0;i<temp-left;i++)
        {
            if(ret[left+i]->left||ret[left+i]->right)
            {
            if(ret[left+i]->left)
            {
            ret[right++]=ret[left+i]->left;
            ret[left+i]->left->val=ret[left+i]->val*10+ret[left+i]->left->val;
            }
            if(ret[left+i]->right)
            {
            ret[right++]=ret[left+i]->right;
            ret[left+i]->right->val=ret[left+i]->val*10+ret[left+i]->right->val;
            }
            }
            else
            {
                sum+=ret[left+i]->val;
            }
        }
        left=temp;
    }
    return sum;
} 