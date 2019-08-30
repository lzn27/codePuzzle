/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode *father;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode *GetNext(TreeNode *pNode){
    if(pNode==nullptr)return nullptr;
    if(pNode->right!=nullptr){
        TreeNode *r=pNode->right;
        while(r->left!=nullptr)r=r->left;
        return r;
    }
    TreeNode *p=pNode;
    if(p->father!=nullptr){
        if(p->father->left==p)
            return p->father;
        p=p->father;
    }
    return nullptr;
}