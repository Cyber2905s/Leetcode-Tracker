class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> pref(n + 1, 0);
        
        // Build prefix sum array
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + nums[i];
        }
        int min_sum = INT_MAX;
        // Check all starting positions and valid lengths [l, r]
        for (int i = 0; i < n; ++i) {
            for (int len = l; len <= r && i + len <= n; ++len) {
                int current_sum = pref[i + len] - pref[i];
                if (current_sum > 0) {
                    min_sum = min(min_sum, current_sum);
                }
            }
        }

        return (min_sum == INT_MAX) ? -1 : min_sum;
    }
};
