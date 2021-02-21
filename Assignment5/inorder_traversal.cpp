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

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->right->left = new TreeNode(40);
    root->right->right = new TreeNode(50);

    inorder(root);
}