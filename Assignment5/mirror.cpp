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
        // constructor chaining
        TreeNode(0);
    }
};

bool isMirror(TreeNode *a, TreeNode *b)
{
    if (a == NULL && b == NULL)
        return true;
    if (a == NULL || b == NULL)
        return false;

    if (a->data == b->data)
    {
        return isMirror(a->left, b->right) && isMirror(a->right, b->left);
    }
    else
    {
        return false;
    }
}

bool isMiror(TreeNode *root)
{
    return isMirror(root->left, root->right);
}
int main()
{
    
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(50);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(70);

    TreeNode *root1 = new TreeNode(10);
    root1->left = new TreeNode(30);
    root1->right = new TreeNode(20);
    root1->left->left = new TreeNode(70);
    root1->left->right = new TreeNode(60);
    root1->right->left = new TreeNode(50);
    root1->right->right = new TreeNode(40);


    cout << isMirror(root, root1);
}