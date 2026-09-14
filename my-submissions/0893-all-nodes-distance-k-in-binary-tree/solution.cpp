/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void MapParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& pmap){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                pmap[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                pmap[node->right] = node;
                q.push(node->right);
            }
        }
    }
    vector<int> bfs(TreeNode* target,unordered_map<TreeNode*,TreeNode*>& pmap,int k){
        queue<TreeNode*> q;
        unordered_set<TreeNode*> vis;
        q.push(target);
        vis.insert(target);
        int clev = 0;
        while(!q.empty()){
            int size = q.size();
            if(clev++==k) break;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && vis.find(node->left)==vis.end()){
                    vis.insert(node->left);
                    q.push(node->left);
                }
                if(node->right && vis.find(node->right)==vis.end()){
                    vis.insert(node->right);
                    q.push(node->right);
                }
                if(pmap.count(node) && vis.find(pmap[node])==vis.end()){
                    vis.insert(pmap[node]);
                    q.push(pmap[node]);
                }
            }
        }
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};
        unordered_map<TreeNode*,TreeNode*> pmap;
        MapParents(root,pmap);
        return bfs(target,pmap,k);
    }
};
