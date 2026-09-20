class Solution {
public:
    int reverseDegree(string s) {
        int total = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int revAlpha = 26 - (s[i] - 'a');
            int pos = i + 1;
            total += revAlpha * pos;
        }
        return total;
    }
};
