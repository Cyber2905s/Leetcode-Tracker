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
    void graph(TreeNode* root,unordered_map<int,vector<int>>& adj){
        if(!root) return;
        if(root->left){
            adj[root->left->val].push_back(root->val);
            adj[root->val].push_back(root->left->val);
            graph(root->left,adj);
        }
        if(root->right){
            adj[root->right->val].push_back(root->val);
            adj[root->val].push_back(root->right->val);
            graph(root->right,adj);
        }
    }
    int maxi(unordered_map<int,vector<int>>& adj,int start){
        if(adj.find(start)==adj.end()) return 0;
        queue<int> q;
        unordered_set<int> vis;
        q.push(start);
        vis.insert(start);
        int maxd = 0;
        while(!q.empty()){
            int size = q.size();
            bool expand = false;
            for(int i=0;i<size;i++){
                int node = q.front();
                q.pop();
                for(int neigh:adj[node]){
                    if(vis.find(neigh)==vis.end()){
                        vis.insert(neigh);
                        q.push(neigh);
                        expand = true;
                    }
                }
            }
            if(expand) maxd++;
        }
        return maxd;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>> adj;
        graph(root,adj);
        return maxi(adj,start);
    }
};
