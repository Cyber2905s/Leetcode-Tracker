class Solution {
public:
    int minimizedStringLength(string s) {
        vector<int> freq(26,0);
        for(char c: s){
            freq[c-'a']++;
        }
        int ans = 0;
        for(int num: freq){
            if(num>=1) ans+=1;
        }
        return ans;
    }
};
