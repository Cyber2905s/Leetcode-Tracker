class Solution {
const int MOD = 1e9+7;
public:
    int countGoodNumbers(long long n) {
        long long odd = n/2;
        long long even = n/2+n%2;
        return (power(5,even)*power(4,odd))%MOD;
    }
    long long power(long long x, long long y){
        if(y==0) return 1;
        long long ans = power(x,y/2);
        ans*=ans;
        ans%=MOD;
        if(y%2) ans*=x;
        ans%=MOD;
        return ans;
    }
};
