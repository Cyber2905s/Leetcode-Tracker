class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        for(char c: columnTitle){
            int val = (c-'A')+1;
            ans*=26;
            ans+=val;
        }
        return ans;
    }
};
