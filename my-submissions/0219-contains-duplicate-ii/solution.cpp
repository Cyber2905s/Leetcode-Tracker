class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> set;
        for(int i=0;i<n;i++){
            if(i>k){
                set.erase(nums[i-k-1]);
            }
            if(set.contains(nums[i])){
                return true;
            }
            set.insert(nums[i]);
        }
        return false;
    }
};
