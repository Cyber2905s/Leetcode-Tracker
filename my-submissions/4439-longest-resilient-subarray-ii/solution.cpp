class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = 1;
        int i =0;
        while(i<n){
            int j = i;
            int rem = nums[i]%k;
            while(j<n && nums[j]%k==rem){
                j++;
            }
            int run_len = j-i;
            if(rem==0){
                maxi = max(maxi,run_len);
            }
            else{
                int g = std::gcd(rem,k);
                int step = k/g;
                if(run_len>=2){
                    int max_m = (run_len-1)/step;
                    if(max_m>=1){
                        int val = 1+max_m*step;
                        maxi = max(maxi,val);
                    }
                }
            }
            i=j;
        }
        return maxi;
    }
};
