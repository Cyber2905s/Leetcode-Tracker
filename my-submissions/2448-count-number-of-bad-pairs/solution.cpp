class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int> freq;
        long long good = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int sum = nums[i]-i;
            good+=freq[sum];
            freq[sum]++;
        }
        long long ans = 1LL * n*(n-1)/2;
        return ans-good;
    }
};
