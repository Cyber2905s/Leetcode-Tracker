class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==1) return nums;
        vector<int> ans;
        int Ccnt = 1;
        for(int r=1;r<n;r++){
            if(nums[r] == nums[r-1]+1){
                Ccnt++;
            }
            else{
                Ccnt = 1;
            }
            if(r>=k-1){
                if(Ccnt>=k){
                    ans.push_back(nums[r]);
                }
                else{
                    ans.push_back(-1);
                }
            }
        }
        return ans;
    }
};
