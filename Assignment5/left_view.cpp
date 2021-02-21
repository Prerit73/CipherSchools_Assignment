#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
    int data;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }

    TreeNode() {
        TreeNode(0);
    }
};

void leftView(TreeNode * root) {
    if (root == NULL)
        return;
    queue<TreeNode *> Q;
    Q.push(root);
    while (!Q.empty()) {
        int size = Q.size();
        for (int i = 0; i < size; i++) {
            root = Q.front(); Q.pop();
            if (i == 0) {
                cout << root->data << " ";
            }
            
            if (root->left != NULL) {
                Q.push(root->left);
            }

            if (root->right != NULL) {
                Q.push(root->right);
            }
        }
    }
}int main()
{

    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(50);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(70);

    leftView(root);
}