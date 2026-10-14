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
    vector<int> findMode(TreeNode* root) {
        map<int,int> freq;
        dfs(root,freq);
        int maxi = 0;
        for(const auto& [key,val]: freq){
            maxi = max(maxi,val);
        }
        vector<int> ans;
        for(const auto& [key,val]: freq){
            if(maxi==val){
                ans.push_back(key);
            }
        }
        return ans;
    }
    void dfs(TreeNode* root, map<int,int>& freq){
        if(!root) return;
        freq[root->val]++;
        dfs(root->left,freq);
        dfs(root->right,freq);
    }
};
