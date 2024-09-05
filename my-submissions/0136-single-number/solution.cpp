class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int s=nums.size();
        int ans=0;
        for(int i=0;i<s;i++){
            ans=ans^nums[i];
        }
        return ans;
        // int ans=nums[s-1];
        // sort(nums.begin(),nums.end());
        // if(s==1){
        //     return nums[0];
        // }
        // int i=0;
        // while(i<s-2){
        //     if(nums[i]==nums[i+1]){
        //         i+=2;
        //     }
        //     else{
        //         return nums[i];
        //     }
        // }
        
        // int max=n;
        // for(int i=0;i<s;i++){
        //     if(nums[i]>max){
        //         max=nums[i];
        //     }
        // }
        // vector<int> hash(max+1,0);
        // for(int i=0;i<s;i++){
        //     hash[nums[i]]++;
        // }
        // for(int i=0;i<max+1;i++){
        //     if(hash[i]==1){
        //         return i;
        //         break;
        //     }
        // }
    }
};
