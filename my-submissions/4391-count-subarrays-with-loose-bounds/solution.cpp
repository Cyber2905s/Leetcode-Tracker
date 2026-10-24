class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0, len = 0;
        for (int x : nums) {
            if (x >= minK && x <= maxK) {
                len++;
                ans += len;
            } else {
                len = 0;
            }
        }
        return ans;
    }
};
