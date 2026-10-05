class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int n = nums.size();
        int l = 0;
        long long pairs = 0;
        long long ans = 0;
        for(int r=0;r<n;r++){
            pairs += freq[nums[r]];
            freq[nums[r]]++;
            while(pairs>=k){
                ans += (n-r);
                freq[nums[l]]--;
                pairs -= freq[nums[l]];
                l++;
            }
        }
        return ans;
    }
};
