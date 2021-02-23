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

void print(TreeNode *root, int k1, int k2)
{
    if (root == NULL)
        return;

    if (k1 < root->data)
        print(root->left, k1, k2);

    if (k1 <= root->data && k2 >= root->data)
        cout << root->data << " ";

    if (k2 > root->data)
        print(root->right, k1, k2);
}

int main()
{
    TreeNode *root = new TreeNode(20);
    int k1 = 10, k2 = 25;

    root->left = new TreeNode(8);
    root->right = new TreeNode(22);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(12);

    print(root, k1, k2);
}
