class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int diff) {
        int n = arr.size();
        int tsum = 0;
        for(auto it: arr){
            tsum+=it;
        }
        if(tsum-diff<0) return 0;
        if((tsum-diff)%2!=0) return 0;
        int target = (tsum-diff)/2;
        vector<int> prev(target+1,0), curr(target+1);
        prev[0]=1;
        if (arr[0] <= target) {
            prev[arr[0]] += 1;
        }
        for(int ind=1;ind<n;ind++){
            for(int sum=0;sum<=target;sum++){
                int notTake = prev[sum];
                int take = 0;
                if(arr[ind]<=sum) take = prev[sum-arr[ind]];
                curr[sum] = notTake+take;
            }
            prev = curr;
        }
        return prev[target];
    }
};
