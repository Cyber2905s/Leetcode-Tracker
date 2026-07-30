class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tgas=0, tcost=0;
        for(int i: gas){
            tgas+=i;
        }
        for(int i: cost){
            tcost+=i;
        }
        if(tgas<tcost) return -1;
        int ans = 0;
        int total = 0;
        for(int i=0;i<gas.size();i++){
            total += gas[i]-cost[i];
            if(total<0){
                total=0;
                ans = i+1;
            }
        }
        return ans;
    }
};
