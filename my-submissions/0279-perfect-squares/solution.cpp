class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,1e9);
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                int notTake = dp[i];
                int take = 1e9;
                if(j*j<=i) take = 1+dp[i-j*j];
                dp[i] = min(take,notTake);
            }
        }
        return dp[n];
    }
};
