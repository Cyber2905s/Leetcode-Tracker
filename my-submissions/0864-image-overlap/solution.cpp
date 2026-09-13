class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<vector<int>> l1,l2;
        int n = img1.size();
        int m = img1[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(img1[i][j]==1){
                    l1.push_back({i,j});
                }
                if(img2[i][j]==1){
                    l2.push_back({i,j});
                }
            }
        }
        int s1 = l1.size();
        int s2 = l2.size();
        map<pair<int,int>,int> mp;
        for(int i=0;i<s1;i++){
            for(int j=0;j<s2;j++){
                int r = l1[i][0]-l2[j][0];
                int c = l1[i][1]-l2[j][1];
                mp[{r,c}]++;
            }
        }
        int maxi = 0;
        for(auto it: mp){
            int cnt = it.second;
            maxi = max(maxi,cnt);
        }
        return maxi;
    }
};
