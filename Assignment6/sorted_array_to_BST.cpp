  
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

TreeNode * sortedArrayToBst(vector<int> vec, int start, int end) {
    if (end < start) {  
        return NULL;
    }
    if (start == end) {
        return new TreeNode(vec[start]);
    }
    
    int mid = start + (end - start)/2;
    TreeNode * newNode = new TreeNode(vec[mid]);
    newNode->left = sortedArrayToBst(vec, start, mid - 1);
    newNode->right = sortedArrayToBst(vec, mid + 1, end);
    return newNode; 
}
void preorder(TreeNode *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
int main(){
    vector<int> vec={1,2,3,4,5,6,7};
    TreeNode *root =sortedArrayToBst(vec,0,6);
    preorder(root);

}