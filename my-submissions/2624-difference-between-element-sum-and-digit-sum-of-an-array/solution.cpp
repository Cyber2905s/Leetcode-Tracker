class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int elesum=0;
        int dsum=0;
        for(int i=0;i<nums.size();i++){
            elesum+=nums[i];
        }
        for(int i=0;i<nums.size();i++){
            int temp=nums[i];
            while(temp>0){
                int t=temp%10;
                dsum+=t;
                temp/=10;
            }
        }
        return abs(elesum-dsum);
    }
};
