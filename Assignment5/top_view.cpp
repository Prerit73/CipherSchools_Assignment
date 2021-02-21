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

void topView(TreeNode *root)
{
    map<int, int> mp;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    while (q.empty() == false)
    {
        auto p = q.front();
        TreeNode *curr = p.first;
        int hd = p.second;
        if (mp.find(hd) == mp.end())
            mp[hd] = (curr->data);
        q.pop();
        if (curr->left != NULL)
            q.push({curr->left, hd - 1});
        if (curr->right != NULL)
            q.push({curr->right, hd + 1});
    }
    for (auto x : mp)
    {
        cout << x.second << " ";
    }
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

    topView(root);
}