class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        vector<int> hash(100001,0);
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                hash[nums[i]]++;
            }
        } 
        int max=0;
        int ans=-1;
        for(int i=0;i<hash.size();i++){
            if(hash[i]>max){
                max=hash[i];
                ans=i;
            }
        }
        return ans;
    }
};
