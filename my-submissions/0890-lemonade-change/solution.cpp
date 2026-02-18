class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> heapm(4,0);
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5) heapm[1]++;
            else if(bills[i]==10){
                if(heapm[1]==0){
                    return false;
                }
                else{
                    heapm[1]--;
                    heapm[2]++;
                }
            }
            else{
                if(heapm[2] && heapm[1]){
                    heapm[1]--;
                    heapm[2]--;
                }
                else if(heapm[1]>=3){
                    heapm[1]-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};
