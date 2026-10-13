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
    vector<int> ans;
    int dfs(TreeNode* root){
        if(!root) return 0;
        int lh = dfs(root->left);
        int rh = dfs(root->right);
        if(lh!=-1 && rh!=-1 && lh==rh){
            int h = 1+lh;
            int size = (1<<h)-1;
            ans.push_back(size);
            return h;
        }
        return -1;
    }
public:
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        ans.clear();
        dfs(root);
        if(ans.size()<k) return -1;
        sort(ans.begin(),ans.end());
        int ind = ans.size()-(k);
        return ans[ind];
    }
};
