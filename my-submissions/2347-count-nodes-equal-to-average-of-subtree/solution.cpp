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
    vector<int> dfs(TreeNode* root,int& nodes){
        if(!root){
            return {0,0};
        }
        vector<int> left = dfs(root->left,nodes);
        vector<int> right = dfs(root->right,nodes);
        int csum = root->val+left[0]+right[0];
        int cnt = 1+left[1]+right[1];
        if(root->val==(csum/cnt)){
            nodes++;
        }
        return {csum,cnt};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int nodes = 0;
        dfs(root,nodes);
        return nodes;
    }
};
