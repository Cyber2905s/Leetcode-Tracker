class Solution {
private:
    bool poss(vector<int> &nums,int div,int t){
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=ceil(static_cast<double>(nums[i])/div);
        }
        return sum<=t;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        if(n>threshold) return -1;
        int l = 1;
        int r = *max_element(nums.begin(),nums.end());
        int ans = r;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(poss(nums,mid,threshold)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};
