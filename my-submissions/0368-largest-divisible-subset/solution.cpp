class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        vector<int> prev(n,-1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[j]+1>dp[i]){
                    dp[i] = dp[j]+1;
                    prev[i] = j;
                }
            }
        }
        int maxi = 0;
        int maxInd = 0;
        for(int i=0;i<n;i++){
            if(maxi<dp[i]){
                maxi = dp[i];
                maxInd = i;
            }
        }
        vector<int> set;
        int curr = maxInd;
        while(curr!=-1){
            set.push_back(nums[curr]);
            curr = prev[curr];
        }
        return set;
    }
};
