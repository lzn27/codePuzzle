#include<iostream>
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
private:
    int *pre = NULL;
public:
    bool isValidBST(TreeNode* root) {
        bool flag = true;
        inorder(root, flag);
        return flag;
    }

    void inorder(TreeNode *node,bool &flag) {
        if (flag == false)
            return;
        if (node == NULL)return;
        inorder(node->left,flag);
        if (pre == 0)pre=new int(node->val);
        else {
            if (node->val <= *pre)flag = false;
            else *pre = node->val;
        }
        inorder(node->right, flag);
    }
};
