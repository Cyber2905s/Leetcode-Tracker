class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        int l =0;
        vector<int> ans;
        for(int r=k-1;r<n;r++){
            bool cond = true;
            for(int i=l+1;i<=r;i++){
                if(nums[i]!=nums[i-1]+1){
                    cond = false;
                    break;
                }
            }
            l++;
            if(cond == true) ans.push_back(nums[r]);
            else ans.push_back(-1);
        }
        return ans;
    }
};
