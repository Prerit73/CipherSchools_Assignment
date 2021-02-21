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

int largestSumSubtree(TreeNode *root, int &res)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = largestSumSubtree(root->left, res);
    int right = largestSumSubtree(root->right, res);

    int curr = (root->data + left + right);
    res = max(res, curr);
    return curr;
}

int largestSumSubtree(TreeNode *root)
{
    int res = INT_MIN;
    largestSumSubtree(root, res);
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
    
    cout << largestSumSubtree(root);
}