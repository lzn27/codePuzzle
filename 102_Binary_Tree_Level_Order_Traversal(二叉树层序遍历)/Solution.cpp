#include<iostream>
#include<vector>
#include<queue>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<pair<TreeNode*, int>> que;
        que.push(pair<TreeNode*, int>(root, 0));
        vector<int> vec;
        while (!que.empty()) {
            auto p = que.front();
            que.pop();
            if (p.second == ans.size())
                vec.push_back(p.first->val);
            else {
                ans.push_back(vec);
                vec.clear();
                vec.push_back(p.first->val);
            }
            if (p.first->left)
                que.push(pair<TreeNode*, int>(p.first->left, p.second + 1));
            if (p.first->right)
                que.push(pair<TreeNode*, int>(p.first->right, p.second + 1));
        }
        if (!vec.empty())
            ans.push_back(vec);
        return ans;
    }

};


int main() {
    Solution solu;

    return 0;
}