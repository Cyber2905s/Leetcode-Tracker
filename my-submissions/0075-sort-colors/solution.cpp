class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s=nums.size();
        for(int i=0;i<s;i++){
            for(int j=i+1;j<s;j++){
                if(nums[i]>nums[j]){
                    swap(nums[i],nums[j]);
                }
                else{
                    continue;
                }
            }
        }
        
    }
};
