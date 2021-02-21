
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

bool isLeaf(TreeNode *root)
{
    return (root->left == NULL && root->right == NULL);
}

int leafToleafMaxSum(TreeNode *root, int sum)
{
    if (root == NULL)
    {
        sum = 0;
        return 0;
    }
    if (isLeaf(root))
    {
        sum = 0;
        return root->data;
    }

    int leftSum = 0, rightSum = 0;
    leftSum = leafToleafMaxSum(root->left, sum);
    rightSum = leafToleafMaxSum(root->right, sum);
    if (root->left != NULL && root->right != NULL)
    {

        sum = max(sum, leftSum + rightSum + root->data);
        return max(leftSum, rightSum) + root->data;
    }
    else if (root->left != NULL)
    {
        return root->data + rightSum;
    }
    else
    {
        return root->data + leftSum;
    }
}
int main(){
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(50);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(70);

    cout<<"Maximum sum of leaf to leaf node "<<leafToleafMaxSum(root,0);
}