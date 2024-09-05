class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int s=nums.size();
        int sum=0;
        for(int i=0;i<s;i++){
            sum+=nums[i];
            if(sum>maxi){
                maxi=sum;
            }
            if(sum<0){
                sum=0;
            }
        }
        return maxi;
        
    }
};
