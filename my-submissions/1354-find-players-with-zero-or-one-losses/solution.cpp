class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> freq;
        vector<int> ans0;
        vector<int> ans1;
        int n = matches.size();
        for(int i=0;i<n;i++){
            freq[matches[i][1]]++;
        }
        unordered_set<int> st0;
        unordered_set<int> st1;
        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                if(freq.find(matches[i][j])==freq.end() && st0.find(matches[i][j])==st0.end()){
                    ans0.push_back(matches[i][j]);
                    st0.insert(matches[i][j]);
                }
                else if(freq[matches[i][j]]==1 && st1.find(matches[i][j])==st1.end()){
                    ans1.push_back(matches[i][j]);
                    st1.insert(matches[i][j]);
                }
            }
        }
        sort(ans0.begin(),ans0.end());
        sort(ans1.begin(),ans1.end());
        return {ans0,ans1};
    }
};
