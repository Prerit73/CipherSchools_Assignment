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

int prevv = INT_MIN;
bool isBST(TreeNode *root)
{
    if (root == NULL)
        return true;

    if (isBST(root->left) == false)
        return false;

    if (root->data <= prevv)
        return false;
    prevv = root->data;

    return isBST(root->right);
}

int main()
{

    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    if (isBST(root))
        cout << "It is BST";
    else
        cout << "Not a BST";
}