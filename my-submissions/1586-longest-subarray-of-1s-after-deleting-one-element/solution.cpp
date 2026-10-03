class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int zero = 0;
        int maxi = 0;
        while(r<n){
            if(nums[r]==0){
                zero++;
            }
            if(zero<=1){
                maxi = max(maxi,r-l);
            }
            while(zero>1){
                if(nums[l]==0){
                    zero--;
                }
                l++;
            }
            r++;
        }
        return maxi;
    }
};
