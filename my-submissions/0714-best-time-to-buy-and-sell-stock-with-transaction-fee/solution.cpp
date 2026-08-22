class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        long ahbuy,ahnbuy;
        ahbuy = ahnbuy = 0;
        for(int ind=n-1;ind>=0;ind--){
            ahnbuy = max(prices[ind]+ahbuy-fee, ahnbuy);
            ahbuy = max(-prices[ind]+ahnbuy, ahbuy);
        }
        return ahbuy;
    }
};
