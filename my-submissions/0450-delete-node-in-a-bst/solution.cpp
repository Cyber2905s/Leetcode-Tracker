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
    TreeNode* del(TreeNode* root,int key){
        if(root==NULL){
            return NULL;
        }
        if(root->val==key){
            if(root->left==NULL){
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }
            else if(root->right==NULL){
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }
            TreeNode* temp = minValueNode(root->right);
            root->val = temp->val;
            root->right = del(root->right, temp->val);
        }
        else if(root->val>key){
            root->left=del(root->left,key);
        }
        else if(root->val<key){
            root->right=del(root->right,key);
        }
        return root;
    }
    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != NULL) {
            current = current->left; 
        }
        return current;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return del(root,key);
    }
};
