class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        long long sum = 0;
        for(int val: nums){
            sum+=val;
        }
        long long target = sum - x;
        if(target<0) return -1;
        if(target==0) return n;
        int l = 0;
        long long csum = 0;
        int maxLen = -1;
        for(int r =0;r<n;r++){
            csum += nums[r];
            while(l<=r && csum>target){
                csum -= nums[l];
                l++;
            }
            if(csum == target){
                maxLen = max(maxLen,r-l+1);
            }
        }
        return (maxLen == -1) ? -1: (n-maxLen);
    }
};
