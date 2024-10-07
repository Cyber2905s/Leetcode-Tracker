/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* LCA(TreeNode* root,int n1,int n2){
        if(root==NULL){return NULL;}
        if(n1<root->val && n2<root->val){
           return LCA(root->left,n1,n2);
        }
        if(n1>root->val && n2>root->val){
            return LCA(root->right,n1,n2);
        }
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return LCA(root,p->val,q->val);
    }
};
