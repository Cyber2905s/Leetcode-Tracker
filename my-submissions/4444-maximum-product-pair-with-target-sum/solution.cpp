class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        int n = nums.size();
        int maxi = INT_MIN;
        bool b = false;
        vector<int> ans = {-1,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && nums[i]+nums[j]==target && nums[i]>nums[j]){
                    int pro = nums[i]*nums[j];
                    if(!b || pro>maxi){
                        maxi = pro;
                        ans = {i,j};
                        b = true;
                    }
                }
            }
        }
        return ans;
    }
};
