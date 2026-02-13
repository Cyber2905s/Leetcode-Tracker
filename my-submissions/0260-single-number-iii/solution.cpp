class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        long xorr = 0;
        int n= nums.size();
        for(int i=0;i<n;i++){
            xorr=xorr^nums[i];
        }
        int rt= (xorr & (xorr-1)) ^ xorr;
        int b1=0;
        int b2=0;
        for(int i=0;i<n;i++){
            if(rt &nums[i]){
            b1=b1^nums[i];
            }
            else{
                b2=b2^nums[i];
            }
        }
        ans.push_back(b1);
        ans.push_back(b2);
        return ans;
    }
};
