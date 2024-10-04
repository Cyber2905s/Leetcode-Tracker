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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int n1=p->val;
        int n2=q->val;
        if(root==NULL){
            return NULL;
        }
        if(root->val==n1||root->val==n2){
            return root;
        }
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(left!=NULL&&right!=NULL){
            return root;
        }
        else if(left!=NULL && right==NULL){
            return left;
        }
        else if(left==NULL && right!=NULL){
            return right;
        }
        else{
            return NULL;
        }
    }
};
