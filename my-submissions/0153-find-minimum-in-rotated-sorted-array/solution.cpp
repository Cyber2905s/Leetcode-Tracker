class Solution {
public:
    int findMin(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        int ans=INT_MAX;
        while(start<=end){
            if(nums[start]<=nums[end]){
                ans=min(ans,nums[start]);
                break;
            }
            int mid=start+(end-start)/2;
            if(nums[mid]>=nums[start]){
                ans=min(ans,nums[start]);
                start=mid+1;
            }
            else{
                ans=min(ans,nums[mid]);
                end=mid-1;
            }
        }
        return ans;
        
    }
};
