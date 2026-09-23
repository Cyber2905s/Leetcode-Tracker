class Solution {
public:
    int ff(vector<int>& nums, int target){
        int ans = -1;
        int n = nums.size();
        int l = 0;
        int r = n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]==target){
                ans = mid;
                r = mid-1;
            }
            else if(nums[mid]>target){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
    int fl(vector<int>& nums, int target){
        int ans = -1;
        int n = nums.size();
        int l = 0;
        int r = n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]==target){
                ans = mid;
                l = mid+1;
            }
            else if(nums[mid]>target){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int first = ff(nums,target);
        if(first==-1) return {};
        int last = fl(nums,target);
        for(int i=first;i<=last;i++){
            ans.push_back(i);
        }
        return ans;
    }
};
