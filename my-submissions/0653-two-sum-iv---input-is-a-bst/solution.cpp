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
    void inorder(TreeNode* n, vector<int>& nums) {
        if (!n) return;
        inorder(n->left, nums);
        nums.push_back(n->val);
        inorder(n->right, nums);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        inorder(root, nums);
        int l = 0, rgt = nums.size() - 1;
        while (l < rgt) {
            int sum = nums[l] + nums[rgt];
            if (sum == k) return true;
            if (sum < k) l++;
            else rgt--;
        }
        return false;
    }
};
