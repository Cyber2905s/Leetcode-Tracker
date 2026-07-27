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
    bool isCompleteTree(TreeNode* root) {
        int index = 0;
        int totalCount = count(root);
        return isCBT(root,index,totalCount);
    }

    int count(TreeNode* root){
        if(root==NULL) return 0;
        int ans = 1+count(root->left)+count(root->right);
        return ans;
    }

    bool isCBT(TreeNode* root, int index, int totalCount){
        if(root==NULL) return true;
        if(index>=totalCount) return false;
        else{
            bool left = isCBT(root->left,2*index+1,totalCount);
            bool right = isCBT(root->right,2*index+2,totalCount);
            return (left && right);
        }
    }
};
