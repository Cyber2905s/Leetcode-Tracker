class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1;
        int inc = 1, dec = 1;
        for(int j=1;j<nums.size();j++){
            int prev = nums[j-1];
            if(nums[j-1]<nums[j]){
                inc++;
                dec = 1;
            }
            else if(nums[j-1]>nums[j]){
                dec++;
                inc = 1;
            }
            else{
                inc = 1;
                dec = 1;
            }
            ans = max({ans,inc,dec});
        }
        return ans;
    }
};
