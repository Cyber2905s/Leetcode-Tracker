class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans;
        for(int i=1;i<n;i++){
            if(!haszero(i) && !haszero(n-i)){
                ans.push_back(i);
                ans.push_back(n-i);
                break;
            }
        }
        return ans;
    }
    bool haszero(int n){
        while(n>0){
            int k = n%10;
            n = n/10;
            if(k==0){
                return true;
                break;
            }
        }
        return false;
    }

};
