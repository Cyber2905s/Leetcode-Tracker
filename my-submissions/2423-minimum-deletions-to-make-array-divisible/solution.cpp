class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int n= numsDivide.size();
        int g=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            g= __gcd(g,numsDivide[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(g % nums[i]== 0) return i;
        }
        return -1;
    }
};
