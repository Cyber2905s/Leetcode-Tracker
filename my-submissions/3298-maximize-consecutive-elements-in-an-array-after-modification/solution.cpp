class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        // Max possible value is 10^6 + 1 after incrementing by 1
        int max_val = nums.back() + 2;
        vector<int> dp(max_val, 0);
        
        int ans = 1;
        
        for (int x : nums) {
            // Update x + 1 first so we don't reuse the same element twice
            dp[x + 1] = max(dp[x + 1], dp[x] + 1);
            dp[x] = max(dp[x], dp[x - 1] + 1);
            
            ans = max({ans, dp[x], dp[x + 1]});
        }
        
        return ans;
    }
};
