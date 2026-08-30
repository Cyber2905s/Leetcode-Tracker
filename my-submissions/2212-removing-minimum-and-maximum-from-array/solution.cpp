class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int maxi=0,mini=0;
        for(int i=0;i<n;i++){
            if(nums[i]>nums[maxi]) maxi = i;
            if(nums[i]<nums[mini]) mini = i;
        }
        int right = max(maxi,mini);
        int left = min(maxi,mini);
        int front = right+1;
        int back = n-left;
        int both = left+(n-right)+1;
        return min(front,min(both,back));
    }
};
