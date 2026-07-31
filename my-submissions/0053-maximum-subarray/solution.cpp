class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = nums[0];
        int csum = 0;
        for(int i: nums){
            csum+=i;
            maxi = max(maxi,csum);
            if(csum<0){
                csum=0;
            }
        }
        return maxi;
    }
};
