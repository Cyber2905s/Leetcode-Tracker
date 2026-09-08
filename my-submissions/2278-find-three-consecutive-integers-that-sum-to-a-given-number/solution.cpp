class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> ans;
        long long s = num/3;
        if(s+(s-1)+(s+1)==num){
            ans.push_back(s-1);
            ans.push_back(s);
            ans.push_back(s+1);
        }
        return ans;
    }
};
