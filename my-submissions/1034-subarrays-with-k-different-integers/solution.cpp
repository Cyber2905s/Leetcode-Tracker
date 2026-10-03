class Solution {
private:
    int helper(vector<int>& nums, int k){
        if(k<0) return 0;
        unordered_map<int,int> map;
        int n = nums.size();
        int l = 0;
        int r = 0;
        int cnt = 0;
        while(r<n){
            map[nums[r]]++;
            while(map.size()>k){
                map[nums[l]]--;
                if(map[nums[l]]==0){
                    map.erase(nums[l]);
                }
                l++;
            }
            cnt += r-l+1;
            r++;
        }
        return cnt;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
    }
};
