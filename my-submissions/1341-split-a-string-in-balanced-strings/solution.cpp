class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0, bal = 0;
        for (char c : s) {
            bal += (c == 'R' ? 1 : -1);
            if (bal == 0) ans++;
        }
        return ans;
    }
};
