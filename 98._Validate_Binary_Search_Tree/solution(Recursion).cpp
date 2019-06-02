#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
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
    bool isValidBST(TreeNode* root) {
        return recursion(root, INT_MAX,INT_MIN,true,true);
    }

    bool recursion(TreeNode *root, int max, int min,bool isMAX,bool isMIN) {
        if (root == NULL)
            return true;
        bool flag = true;

        if (!isMAX) {
            if (!(root->val < max))
                flag = false;
        }
        if (!isMIN) {
            if (!(root->val > min))
                flag = false;
        }

        if (root->left) {
            if (root->left->val >= root->val)
                flag = false;
        }
        if (root->right) {
            if (root->right->val <= root->val)
                flag = false;
        }
        if (flag)
            return recursion(root->left, root->val, min, false, isMIN) && recursion(root->right, max, root->val, isMAX, false);
        else
            return false;
    }
};


int main() {
    Solution solu;

    return 0;
}