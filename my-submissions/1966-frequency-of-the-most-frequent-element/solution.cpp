class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long total = 0;
        int count = 0;
        int l = 0;
        for(int r=0;r<n;r++){
            total+=nums[r];
            while((long long)(r-l+1)*nums[r]-total>k){
                total-=nums[l];
                l++;
            }
            count = max(count,r-l+1);
        }
        return count;
    }
};
