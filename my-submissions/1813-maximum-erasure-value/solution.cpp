class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0; 
        int sum = 0;
        int maxi = -1e9;
        unordered_set<int> st;
        for(int r=0;r<n;r++){
            while(st.find(nums[r])!=st.end()){
                st.erase(nums[l]);
                sum-=nums[l];
                l++;
            }
            st.insert(nums[r]);
            sum+=nums[r];
            maxi = max(maxi,sum);
        }
        return maxi;
    }
};
