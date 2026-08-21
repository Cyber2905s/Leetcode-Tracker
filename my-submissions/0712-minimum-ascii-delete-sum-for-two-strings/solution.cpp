class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        int tsum = 0;
        for(char c: s1) tsum+=(int)c;
        for(char c: s2) tsum+=(int)c;
        vector<int> prev(m+1,0),curr(m+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    curr[j] = (int)s1[i-1]+prev[j-1];
                }
                else{
                    curr[j] = max(prev[j],curr[j-1]);
                }
            }
            prev = curr;
        }
        return tsum-2*prev[m];
    }
};
