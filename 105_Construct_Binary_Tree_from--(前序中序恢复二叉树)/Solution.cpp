#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

    class Solution {
    public:
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            return recursion(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
        
        }

        TreeNode *recursion(vector<int>& preorder, int pl, int pr, vector<int>& inorder, int il, int ir) {
            if (pr < pl || ir < il)
                return NULL;
            TreeNode *root;
            root = new TreeNode(preorder[pl]);
            vector<int>::iterator it = find(inorder.begin()+il, inorder.begin()+ir+1, preorder[pl]);
            int index = it - inorder.begin();
            int lcNum = index - il;
            root->left = recursion(preorder, pl + 1, pl + lcNum, inorder, il, index-1);
            root->right = recursion(preorder, pl + lcNum + 1, pr, inorder, index + 1, ir);
            return root;
        }
    };

int main() {
    Solution solu;

    return 0;
}