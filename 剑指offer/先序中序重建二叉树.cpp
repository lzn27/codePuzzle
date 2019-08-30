/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


//注意下标加减计算数量的细节。
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int>& pre, vector<int>& vin) {
        if (pre.size() == 0 || vin.size() == 0)
            return nullptr;
        return recursion(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
    }
    TreeNode* recursion(vector<int>& pre, int pl, int pr, vector<int>& vin, int vl, int vr) {
        if (pl > pr || vl > vr)
            return nullptr;
        TreeNode *head = new TreeNode(pre[pl]);
        int indexheadvin = vl;
        while (vin[indexheadvin] != pre[pl])indexheadvin++;
        int leftchildnum = indexheadvin - vl;
        int rightchildnum = vr - indexheadvin;
        head->left = recursion(pre, pl + 1, pl + leftchildnum, vin, vl, indexheadvin - 1);
        head->right = recursion(pre, pl + leftchildnum + 1, pr, vin, indexheadvin + 1, vr);
        return head;
    }
};