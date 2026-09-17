class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<long long> seen;
        for(int i=0;i<n-1;i++){
            long long csum = (long long)nums[i]+nums[i+1];
            if(seen.find(csum)!=seen.end()){
                return true;
            }
            seen.insert(csum);
        }
        return false;
    }
};
