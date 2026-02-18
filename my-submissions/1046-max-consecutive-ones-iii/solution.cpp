class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n= nums.size();
        int l=0,r=0;
        int zeros=0;
        int maxl=0;
        while(r<n){
            if(nums[r]==0){
               zeros++;
            }
            if(zeros>k){
                if(nums[l]==0){
                    zeros--;
                }
                l++;
            }
            if(zeros<=k){
                maxl= max(r-l+1,maxl);
            }
            r++;
        }
        return maxl;
    }
};
