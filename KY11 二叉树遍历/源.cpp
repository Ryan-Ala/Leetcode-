#include <stdio.h>
#include<stdlib.h>
typedef struct TreeNode
{
    char val;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* CreatTree(char* arr, int* size)
{
    if (arr[*size] == '#' || arr[*size] == '\0')
    {
        (*size)++;
        return NULL;
    }
    TreeNode* newnode = (TreeNode*)malloc(sizeof(TreeNode));
    newnode->val = arr[(*size)++];
    newnode->left = CreatTree(arr, size);
    newnode->right = CreatTree(arr, size);
    return newnode;
}

void Prev(struct TreeNode* root)
{
    if (!root)
        return;
    Prev(root->left);
    printf("%c ", root->val);
    Prev(root->right);
}

void Destory(struct TreeNode* root)
{
    if (!root)
        return;
    Destory(root->left);
    Destory(root->right);
    free(root);
}


int main() {
    char arr[101] = { 0 };
    int size = 0;


    //每次读取一段字符串，若读取错误则退出循环   ( 读取错误会返回 EOF )
    while (scanf("%s", &arr) != EOF)  //之后每次循环运行
    {

        TreeNode* root = CreatTree(arr, &size);

        Prev(root);

        Destory(root);

    }
}