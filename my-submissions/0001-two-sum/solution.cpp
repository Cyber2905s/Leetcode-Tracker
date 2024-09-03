class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                bool b=true;
                if(nums[i]+nums[j]==target){
                    b=false;
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
                if(b==false){
                    break;
                }
            }
        }
        return ans;
        
    }
};
