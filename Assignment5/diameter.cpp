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

int res = 0;
int height(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    res = max(res, 1 + lh + rh);

    return 1 + max(lh, rh);
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->right->left = new TreeNode(40);
    root->right->right = new TreeNode(60);
    root->right->left->left = new TreeNode(50);
    root->right->right->right = new TreeNode(70);

    cout << "Height " << height(root) << endl;
    cout << "Diameter " << res;
}