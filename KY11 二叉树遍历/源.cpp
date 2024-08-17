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


    //ÿ�ζ�ȡһ���ַ���������ȡ�������˳�ѭ��   ( ��ȡ����᷵�� EOF )
    while (scanf("%s", &arr) != EOF)  //֮��ÿ��ѭ������
    {

        TreeNode* root = CreatTree(arr, &size);

        Prev(root);

        Destory(root);

    }
}