class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;
        int maxi = *max_element(nums.begin(),nums.end());
        for(int num: nums){
            ans += (maxi-num);
        }
        return ans;
    }
};
