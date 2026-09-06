class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int num:nums){
            if(num<k) ans++;
            else if(num>=k) break;
        }
        return ans;
    }
};
