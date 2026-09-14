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
    int fhl(TreeNode* node){
        int h =0;
        while(node){
            h++;
            node = node->left;
        }
        return h;
    }
    int fhr(TreeNode* node){
        int h =0;
        while(node){
            h++;
            node = node->right;
        }
        return h;
    }
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh = fhl(root);
        int rh = fhr(root);
        if(rh==lh) return (1<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);        
    }
};
