class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        
        for (int i = 0; i < n; ++i) {
            int index = nums[i] - 1;
            ans[index] = 1;
        }
        
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (ans[i] == 0) {
                result.push_back(i + 1);
            }
        }
        
        return result;
    }
};
