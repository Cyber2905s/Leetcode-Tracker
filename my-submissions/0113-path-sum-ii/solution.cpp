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
    void ans(TreeNode* root,int t,vector<vector<int>>& res,vector<int>& ds){
        if(!root) return;
        ds.push_back(root->val);
        if(!root->right && !root->left && root->val==t){
            res.push_back(ds);
        }
        ans(root->left,t-root->val,res,ds);
        ans(root->right,t-root->val,res,ds);
        ds.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> ds;
        ans(root,targetSum,res,ds);
        return res;
    }
};
