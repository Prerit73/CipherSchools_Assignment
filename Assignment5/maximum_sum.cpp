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

int maxSumSubtree(TreeNode *root, int &res)
{
    if (root == NULL)
    {
        return 0;
    }
    int l = maxSumSubtree(root->left, res);
    int r = maxSumSubtree(root->right, res);

    int curr = (root->data + l + r);
    res = max(res, curr);
    return curr;
}

int maxSumSubtree(TreeNode *root)
{
    int res = INT_MIN;
   maxSumSubtree(root, res);
    return res;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    cout << maxSumSubtree(root);
}