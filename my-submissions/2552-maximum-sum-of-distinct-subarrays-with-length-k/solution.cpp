class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        long long sum = 0;
        int r = 0;
        long long maxi = 0;
        unordered_set<int> st;
        while(r<n){
            while(st.find(nums[r])!=st.end()){
                st.erase(nums[l]);
                sum-=nums[l];
                l++;
            }
            sum+=nums[r];
            st.insert(nums[r]);
            if(r-l+1>k){
                sum-=nums[l];
                st.erase(nums[l]);
                l++;
            }
            if(r-l+1 == k){
                maxi = max(maxi,sum);
            }
            r++;
        }
        return maxi;
    }
};
