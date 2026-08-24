class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int ssum = 0;
        int dsum = 0;
        for(int num:nums){
            int cnt = 0;
            int temp = num;
            while(temp>0){
                temp/=10;
                cnt++;
            }
            if(cnt == 1) ssum+=num;
            else dsum+= num;
        }
        return (dsum>ssum || ssum>dsum);
    }
};
