class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            if(queries[i][1]<nums.size()) nums[queries[i][1]]+=queries[i][0];
            else continue;
            for(int j=0;j<nums.size();j++){
                if(nums[j]%2==0) ans[i]+= nums[j];
            }
        }
        return ans;
    }
};
