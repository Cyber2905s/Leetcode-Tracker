/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        func(root->left,root->right,1);
        return root;
    }
    void func(TreeNode* leftN,TreeNode* rightN,int lev){
        if(!leftN || !rightN) return;
        if(lev%2==1) swap(leftN->val,rightN->val);
        func(leftN->left,rightN->right,lev+1);
        func(leftN->right,rightN->left,lev+1);
    }
};
