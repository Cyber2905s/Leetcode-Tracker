class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> sq(n);
        for(int i=0;i<n;i++){
            sq[i] = 1LL*nums[i]*nums[i];
        }
        sort(sq.begin(),sq.end());
        long long ans = 0;
        int l = 0;
        int r = n-1;
        while(l<r){
            ans+=sq[r];
            ans-=sq[l];
            r--;
            l++;
        }
        if(l==r){
            ans+=sq[l];
        }
        return ans;
    }
};
