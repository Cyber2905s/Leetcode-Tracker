class Solution {
public:
    bool subsetSum(vector<int>& arr,int sum){
        int n = arr.size();
        vector<bool> prev(sum+1,0), curr(sum+1,0);
        prev[0]=curr[0]=true;
        if (arr[0] <= sum) {
            prev[arr[0]] = true;
        }
        for(int ind=1;ind<n;ind++){
            for(int target=1;target<=sum;target++){
                bool notTake = prev[target];
                bool take = false;
                if(arr[ind]<=target) take = prev[target-arr[ind]];
                curr[target] = take | notTake;
            }
            prev = curr;
        }
        return prev[sum];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int tsum = 0;
        for(auto it: nums){
            tsum+=it;
        }
        if(tsum%2) return false;
        int target = tsum/2;
        return subsetSum(nums,target);
    }
};
