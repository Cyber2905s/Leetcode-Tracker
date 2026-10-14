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
    int func(TreeNode* root,int& maxi){
        if(!root) return 0;
        int ll = func(root->left,maxi);
        int rl = func(root->right,maxi);
        int arrowLeft = 0;
        int arrowRight = 0;
        if(root->left && root->left->val==root->val){
            arrowLeft = ll+1;
        }
        if(root->right && root->right->val==root->val){
            arrowRight = rl+1;
        }
        maxi = max(maxi,arrowLeft+arrowRight);
        return max(arrowLeft,arrowRight);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        int maxi = 0;
        func(root,maxi);
        return maxi;
    }
};
