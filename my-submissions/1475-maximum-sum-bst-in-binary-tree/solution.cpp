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
class NodeValue{
public:
    int maxNode, minNode, sum;
    NodeValue(int minNode,int maxNode,int sum){
        this->maxNode = maxNode,
        this->minNode = minNode;
        this->sum = sum;
    }
};
class Solution {
private:
    int ans = 0;
    NodeValue helper(TreeNode* root){
        if(!root){
            return NodeValue(INT_MAX,INT_MIN,0);
        }
        auto left = helper(root->left);
        auto right = helper(root->right);
        if(left.maxNode < root->val && root->val < right.minNode){
            int csum = left.sum+right.sum+root->val;
            ans = max(ans,csum);
            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode),csum);
        }
        return NodeValue(INT_MIN,INT_MAX,0);
    }
public:
    int maxSumBST(TreeNode* root) {
        helper(root);
        return ans;
    }
};
