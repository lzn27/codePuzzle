#include<iostream>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        return isMirror(root->left, root->right);

    }
    bool isMirror(TreeNode *r1, TreeNode *r2) {
        if (r1&&r2&&r1->val == r2->val)
            return isMirror(r1->left, r2->right) && isMirror(r1->right, r2->left);
        else {
            if (r1 == NULL && r2 == NULL)
                return true;
            else
                return false;
        }
    }
};


int main() {
    Solution solu;

    return 0;
}