class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int size=nums.size();
        int hash[101];
        for(int i=0;i<size;i++){
            hash[nums[i]]++;
        }
        int max=-1;
        for(int i=0;i<101;i++){
            if(hash[i]>max){
                max=hash[i];
            }
        }
        int count=0;
        for(int i=0;i<101;i++){
            if(hash[i]==max){
                count=count+max;
            }
        }
        return count;
        
    }
};
