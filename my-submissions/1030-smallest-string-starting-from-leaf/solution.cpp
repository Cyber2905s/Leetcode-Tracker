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
    string small = "";
public:
    string smallestFromLeaf(TreeNode* root) {
       dfs(root,"");
       return small;
    }
    void dfs(TreeNode* root, string s){
        if(!root) return;
        s+=root->val+'a';
        if(!root->left && !root->right){
            reverse(s.begin(),s.end());
            if(!small.size()) small=s;
            else small=min(small,s);
            return;
        }
        dfs(root->right,s);
        dfs(root->left,s);
    }
};
