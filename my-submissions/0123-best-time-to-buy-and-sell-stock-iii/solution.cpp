class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(5, 0);
        for(int ind=n-1;ind>=0;ind--){
            for(int trans = 0; trans < 4; trans++){
                if(trans%2==0){
                    dp[trans] = max(-prices[ind] + dp[trans + 1], dp[trans]);
                }
                else{
                    dp[trans] = max(prices[ind] + dp[trans + 1], dp[trans]);
                }
            }
        }
        return dp[0];
    }
};
