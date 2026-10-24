class Solution {
public:
    int countMagicalPairs(string s) {
        int n = s.length();
        long long a = 0;
        string m = s;
        for (int j = 0; j < n - 1; ++j) {
            int c1[26] = {0}, d1 = 0, cnt1[27] = {0};
            for (int i = j; i >= 0; --i) {
                if (!c1[m[i] - 'a']++) d1++;
                cnt1[d1]++;
            }
            int c2[26] = {0}, d2 = 0, cnt2[27] = {0};
            for (int k = j + 1; k < n; ++k) {
                if (!c2[m[k] - 'a']++) d2++;
                cnt2[d2]++;
            }
            for (int d = 1; d <= 26; ++d) {
                a += (long long)cnt1[d] * cnt2[d];
            }
        }
        return a;
    }
};
