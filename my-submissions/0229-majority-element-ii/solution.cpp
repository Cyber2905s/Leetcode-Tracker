class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int can1 = 0;
        int can2 = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        for(int num:nums){
            if(can1 == num){
                cnt1++;
            }
            else if(can2 == num){
                cnt2++;
            }
            else if(cnt1 == 0){
                can1 = num;
                cnt1++;
            }
            else if(cnt2 == 0){
                can2 = num;
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        int count1 = 0;
        int count2 = 0;
        for(int num:nums){
            if(num==can1) count1++;
            else if(num==can2) count2++;
        } 
        if(count1>n/3) ans.push_back(can1);
        if(count2>n/3) ans.push_back(can2);
        return ans;
    }
};
