class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long num = 1;
        for(int i=1;i<=5;i++){
            num*=1000;
            if(n>=num) ans+=n-num+1;
        }
        return ans;
    }
};
