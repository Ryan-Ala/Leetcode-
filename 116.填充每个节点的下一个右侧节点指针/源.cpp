#include<iostream>
  struct Node {
      int val;
     struct Node *left;
     struct Node *right;
     struct Node *next;
};

struct Node* connect(struct Node* root) {
    if (!root)
        return NULL;
    int k = 0;
    struct Node* res[4100];
    int left = 0, right = 0, temp = 0;
    res[right++] = root;
    root->next = NULL;
    while (right != left)
    {
        temp = right;
        for (int i = 0; i < temp - left; i++)
        {
            if (i != temp - left - 1)
                res[i + left]->next = res[i + left + 1];
            if (res[i + left]->left)
                res[right++] = res[i + left]->left;
            if (res[i + left]->right)
                res[right++] = res[i + left]->right;
        }
        res[right - 1]->next = NULL;
        left = temp;
    }
    return root;
}