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

void printKDist(TreeNode *root, int k)
{
    if (root == NULL)
        return;

    if (k == 0)
    {
        cout << root->data << " ";
    }
    else
    {
        printKDist(root->left, k - 1);
        printKDist(root->right, k - 1);
    }
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(50);
    root->right->right = new TreeNode(70);
    root->right->right->right = new TreeNode(80);
    int k = 2;

    printKDist(root, k);
}