class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans=INT_MIN;
        int m = accounts.size();
        for(int i=0;i<m;i++){
            int n = accounts[i].size();
            int sum=0;
            for(int j=0;j<n;j++){
                sum+=accounts[i][j];
            }
            if(sum>ans){
                ans=sum;
            }
        }
        return ans;
    }
};
