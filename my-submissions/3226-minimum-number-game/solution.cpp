class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> ans(n,0);
        ans = nums;
        for(int i=0;i<n;i+=2){
            swap(ans[i],ans[i+1]);
        }
        return ans;
    }
};
