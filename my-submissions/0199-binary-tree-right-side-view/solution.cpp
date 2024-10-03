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
void solve(vector<int> &ans,TreeNode* root,int level){
    if(root==NULL){
        return ;
    }
    //naye level mei aa gaye hai
    if(level==ans.size()){
        ans.push_back(root->val);
    }
    //call right to left ja rahi hai kyuki right view print karwana hai
    solve(ans,root->right,level+1);
    solve(ans,root->left,level+1);
}
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(ans,root,0);
        return ans;
    }
};
