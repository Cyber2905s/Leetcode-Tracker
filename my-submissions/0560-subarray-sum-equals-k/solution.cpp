class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int s=nums.size();
        int count=0;
        for(int i=0;i<s;i++){
            int sum=0;
            for(int j=i;j<s;j++){
                sum+=nums[j];
                if(sum==k){
                    count++;
                }
            }
        }
        return count;
        
    }
};
