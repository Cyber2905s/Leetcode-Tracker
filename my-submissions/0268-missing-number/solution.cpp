class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s=nums.size();
        vector<int> hash(s+1,0);
        for(int i=0;i<s;i++){
            hash[nums[i]]++;
        }
        for(int i=0;i<s+1;i++){
            if(hash[i]==0){
                return i;
                break;
            }
        }
        return 0;
    }
};
