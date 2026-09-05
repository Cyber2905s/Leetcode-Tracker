class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pmax = nums[0];
        int pmin = nums[0];
        int pro = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                swap(pmax,pmin);
            }
            pmax = max(nums[i],pmax*nums[i]);
            pmin = min(nums[i],pmin*nums[i]);
            pro = max(pro,pmax);
        }
        return pro;
    }
};
