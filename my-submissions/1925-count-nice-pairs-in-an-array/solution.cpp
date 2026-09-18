class Solution {
private:
    int rev(int n){
        int ans = 0;
        while(n>0){
            int a = n%10;
            ans*=10;
            ans+=a;
            n/=10;
        }
        return ans;
    }
public:
    int countNicePairs(vector<int>& nums) {
        int mod = 1e9+7;
        int cnt = 0;
        unordered_map<int,int> freq;
        for(int num: nums){
            int diff = num-rev(num);
            cnt = (cnt+freq[diff])%mod;
            freq[diff]++;
        }
        return cnt%mod;
    }
};
