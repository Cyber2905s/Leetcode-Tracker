class Solution {
private:
    int poss(vector<int> &arr, long long maxi){
        int cnt = 1;
        long long pages = 0;
        for(int i=0;i<arr.size();i++){
            if(pages+arr[i]<=maxi){
                pages+=arr[i];
            }
            else{
                cnt++;
                pages = arr[i];
            }
        }
        return cnt;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<k) return -1;
        int ans = -1;
        long long l = *max_element(nums.begin(),nums.end());
        long long r = accumulate(nums.begin(),nums.end(),0LL);
        while(l<=r){
            int mid = l+(r-l)/2;
            if(poss(nums,mid)<=k){
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
