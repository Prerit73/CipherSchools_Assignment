#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }

    TreeNode()
    {
        TreeNode(0);
    }
};

void inorder(TreeNode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int preIndex = 0;
TreeNode *cTree(int in[], int pre[], int is, int ie)
{
    if (is > ie)
        return NULL;
    TreeNode *root = new TreeNode(pre[preIndex++]);

    int inIndex;
    for (int i = is; i <= ie; i++)
    {
        if (in[i] == root->data)
        {
            inIndex = i;
            break;
        }
    }
    root->left = cTree(in, pre, is, inIndex - 1);
    root->right = cTree(in, pre, inIndex + 1, ie);
    return root;
}

int main()
{

    int in[] = {20, 10, 40, 30, 50};
    int pre[] = {10, 20, 30, 40, 50};
    int n = sizeof(in) / sizeof(in[0]);
    TreeNode *root = cTree(in, pre, 0, n - 1);
    inorder(root);
}