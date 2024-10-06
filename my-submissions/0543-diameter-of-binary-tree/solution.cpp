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
 /*int height(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    return (max(left,right)+1);
 }*/
 //optimized solution
 pair<int,int> dfast(TreeNode* root){
    if(root==NULL){
        return make_pair(0,0);
    }
    pair<int,int> left=dfast(root->left);
    pair<int,int> right=dfast(root->right);
    int left1=left.first;
    int right1=right.first;
    int combo=left.second+right.second;
    pair<int,int> ans;
    ans.first=max(left1,max(right1,combo));
    ans.second=(max(left.second,right.second)+1);
    return ans;
 }
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        /*if(root==NULL){
            return 0;
        }
        int left=diameterOfBinaryTree(root->left);
        int right=diameterOfBinaryTree(root->right);
        int combo=height(root->left)+height(root->right);
        return max(left,max(right,combo));*/
        return dfast(root).first;
    }
};
