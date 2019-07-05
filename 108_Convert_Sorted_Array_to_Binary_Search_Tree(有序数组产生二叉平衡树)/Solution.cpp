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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recursion(nums, 0, nums.size() - 1);
    }
    TreeNode* recursion(vector<int>& nums, int l, int r) {
        if (r < l)
            return NULL;
        int mid = (l + r) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = recursion(nums, l, mid - 1);
        root->right = recursion(nums, mid + 1, r);
        return root;
    }
};

int main() {
    Solution solu;

    return 0;
}