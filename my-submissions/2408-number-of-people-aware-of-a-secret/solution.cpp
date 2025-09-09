class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int mod = 1e9+7;
        vector<int> dp(n+1);
        dp[1]=1;
        int win_cnt=0;
        for(int i=2;i<=n;i++){
            if(i-delay > 0){
                win_cnt = (win_cnt + dp[i-delay]) % mod;
            }
            if(i-forget > 0){
                win_cnt = (win_cnt - dp[i-forget] + mod) % mod;
            }
            dp[i] = win_cnt;
        }
        int total = 0;
        for(int i=n-forget+1;i<=n;i++){
            total = (total + dp[i]) % mod;
        }
        return total;
    }
};
