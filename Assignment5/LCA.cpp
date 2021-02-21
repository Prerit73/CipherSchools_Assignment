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

TreeNode *lca(TreeNode *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;
    if (root->data == n1 || root->data == n2)
        return root;

    TreeNode *lca1 = lca(root->left, n1, n2);
    TreeNode *lca2 = lca(root->right, n1, n2);

    if (lca1 != NULL && lca2 != NULL)
        return root;
    if (lca1 != NULL)
        return lca1;
    else
        return lca2;
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->right->left = new TreeNode(40);
    root->right->right = new TreeNode(50);
    int n1 = 20, n2 = 50;

    TreeNode *ans = lca(root, n1, n2);
    cout << "LCA " << ans->data;
}