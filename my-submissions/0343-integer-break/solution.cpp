class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,1);
        for(int num=2;num<n;num++){
            for(int target=0;target<=n;target++){
                int notTake = dp[target];
                int take = 0;
                if(num<=target){
                    take = num*dp[target-num];
                }
                dp[target] = max(take,notTake);
            }
        }
        return dp[n];
    }
};
