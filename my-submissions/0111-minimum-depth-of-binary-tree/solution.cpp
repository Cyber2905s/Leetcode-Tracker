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
private:
    int height(TreeNode* root){
        if(!root) return 0;
        if(!root->right) return 1+height(root->left);
        if(!root->left) return 1+height(root->right);
        return 1+min(height(root->right),height(root->left));
    }
public:
    int minDepth(TreeNode* root) {
        return height(root);
    }
};
