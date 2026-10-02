class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int maxi = -1e9;
        int used = 0;
        for(int r=0;r<n;r++){
            while((used & nums[r]) != 0){
                used ^= nums[l];
                l++;
            }
            used |= nums[r];
            maxi = max(maxi,r-l+1);
        }
        return maxi;
    }
};
