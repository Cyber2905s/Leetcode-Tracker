class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        long long top1 = 0;
        long long top2 = 0;
        for(int num:nums){
            long long val = abs(num);
            if(val>top1){
                top2 = top1;
                top1 = val;
            }
            else if(val>top2){
                top2 = val;
            }
        }
        return (top1*top2*1e5);
    }
};
