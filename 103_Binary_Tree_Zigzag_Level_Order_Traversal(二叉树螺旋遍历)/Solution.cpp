#include<iostream>
#include<vector>
#include<stack>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        stack<TreeNode*> lsta, rsta;
        if (root == NULL)
            return ans;
        lsta.push(root);
        bool flag = true;
        while (!(lsta.empty() && rsta.empty())) {
            if (flag) {
                vector<int> vec;
                while(!lsta.empty()){
                    TreeNode* p = lsta.top();
                    lsta.pop();
                    vec.push_back(p->val);
                    if (p->left)
                        rsta.push(p->left);
                    if (p->right)
                        rsta.push(p->right);
                }
                ans.push_back(vec);
            }
            else {
                vector<int> vec;
                while (!rsta.empty()) {
                    TreeNode* p = rsta.top();
                    rsta.pop();
                    vec.push_back(p->val);
                    if (p->right)
                        lsta.push(p->right);
                    if (p->left)
                        lsta.push(p->left);
                }
                ans.push_back(vec);
            }
            flag = !flag;
        }
        return ans;
        
    }
};


int main() {
    Solution solu;

    return 0;
}