class Solution {
public:
    int numSub(string s) {
        long long ans = 0;
        long long ones = 0;
        const int mod = 1e9+7;
        for(char c:s){
            if(c=='1'){
                ones++;
                ans = (ans+ones)%mod;
            }
            else{
                ones = 0;
            }
        }
        return ans;
    }
};
