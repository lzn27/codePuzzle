#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)
            return root;
        queue<Node*> que;
        que.push(root);
        int num = 0;
        int lastNum = 0;
        while (!que.empty()) {
            Node* p = que.front();
            que.pop();

            //====遍历节点====
            num++;
            if (num == lastNum * 2 + 1) {
                lastNum = num;
                p->next = NULL;
            }
            else {
                p->next = que.front();
            }
            //===========

            if (p->left)
                que.push(p->left);
            if (p->right)
                que.push(p->right);
        }
        return root;
    }
};

int main() {
    Solution solu;

    return 0;
}