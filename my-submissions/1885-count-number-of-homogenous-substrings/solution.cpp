class Solution {
public:
    int countHomogenous(string s) {
        long long ans = 1;
        const int mod = 1e9+7;
        long long cont = 1;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                cont++;
                ans = (ans+cont)%mod;
            }
            else{
                cont = 1;
                ans = (ans+cont)%mod;
            }
        }
        return ans;
    }
};
