#include<iostream>
#include<algorithm>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* head = new TreeNode(0);
        TreeNode* p = head;
        treeToList(root, p);
        delete head;
    }
    void treeToList(TreeNode* root,TreeNode *&p) {
        if (!root)return;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        p->right = root;
        p->left = NULL;
        p = p->right;
        if (left)
            treeToList(left, p);
        if(right)
            treeToList(right, p);
    }
};
//----------------------
int main() {
    Solution solu;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    solu.flatten(root);
    TreeNode* p = root;
    while (p) {
        cout << p->val;
        p = p->right;
    }
    return 0;
}