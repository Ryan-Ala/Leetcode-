#include<iostream>
struct Node {
    int val;
    struct Node* left;
    struct Node* right;
    struct Node* next;
};
struct Node* connect(struct Node* root) {
    if (!root)
        return NULL;
    struct Node* ret[6001];
    int left = 0, right = 0, temp = 0;
    ret[right++] = root;
    while (left < right)
    {
        temp = right;
        for (int i = 0; i < temp - left; i++)
        {
            if (i < temp - left - 1)
                ret[left + i]->next = ret[left + i + 1];
            else
                ret[left + i]->next = NULL;
            if (ret[i + left]->left)
                ret[right++] = ret[left + i]->left;
            if (ret[i + left]->right)
                ret[right++] = ret[left + i]->right;
        }
        left = temp;
    }
    return root;
}