class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int biti=0;biti<32;biti++){
            int cnt=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]&(1<<biti)){
                    cnt++;
                }
            }
            if(cnt%3==1){
                ans=ans|(1<<biti);
            }
        }
        return ans;
    }
};
