class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            unordered_map<char,int> mp;
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                int maxi = -1e9;
                int mini = 1e9;
                for(auto it: mp){
                    maxi = max(maxi,it.second);
                    mini = min(mini,it.second);
                }
                sum+=(maxi-mini);
            }
        }
        return sum;
    }
};
