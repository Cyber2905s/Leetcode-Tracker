class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        // Case 1: Change the 2 smallest elements -> range is nums[n-1] - nums[2]
        int case1 = nums[n - 1] - nums[2];

        // Case 2: Change 1 smallest and 1 largest -> range is nums[n-2] - nums[1]
        int case2 = nums[n - 2] - nums[1];

        // Case 3: Change the 2 largest elements -> range is nums[n-3] - nums[0]
        int case3 = nums[n - 3] - nums[0];

        return min({case1, case2, case3});
    }
};
