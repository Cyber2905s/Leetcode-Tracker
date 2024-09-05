class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        // vector<int> answer;
        int s=nums.size();
        int max=0;
        int i=0;
        while(i<s){
            if(nums[i]==1){
                count++;
                i++;
            }
            else if(nums[i]==0){
                if(count>max){
                    max=count;
                }
                count=0;
                i++;
            }
            if(count>max){
                max=count;
            }
        }
        return max;
        
    }
};
