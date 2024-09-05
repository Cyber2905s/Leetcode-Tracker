class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int s=prices.size();
        int mini=INT_MAX;
        int profit=0;
        for(int i=0;i<s;i++){
            mini=min(prices[i],mini);
            profit=max(profit,prices[i]-mini);
        }
        return profit;
        
    }
};
