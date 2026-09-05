class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int can = 0;
        int cnt = 0;
        for(int num:nums){
            if(cnt==0){
                can = num;
                cnt++;
            }
            else if(can==num){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return can;
    }
};
