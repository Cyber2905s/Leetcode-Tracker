class Solution {
private:
    bool poss(vector<int>& nums,int w,int d){
        int cnt = 1;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]>w){
                cnt++;
                sum=0;
            }
            sum+=nums[i];
        }
        return cnt<=d;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(),weights.end());
        int r = 0;
        for(int num:weights){
            r+=num;
        }
        int ans = r;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(poss(weights,mid,days)){
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
