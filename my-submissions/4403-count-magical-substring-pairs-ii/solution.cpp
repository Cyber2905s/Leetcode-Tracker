class Solution {
public:
    long long countMagicalPairs(string s) {
        int n = s.size();
        string z = s;
        vector<array<int, 26>> nx(n + 1);
        nx[n].fill(n);
        for (int i = n - 1; i >= 0; --i) {
            nx[i] = nx[i + 1];
            nx[i][z[i] - 'a'] = i;
        }

        int last[26];
        fill(last, last + 26, -1);

        long long ans = 0;
        for (int j = 0; j < n - 1; ++j) {
            last[z[j] - 'a'] = j;

            vector<int> p, q;
            for (int c = 0; c < 26; ++c) {
                if (last[c] >= 0) p.push_back(last[c]);
                if (nx[j + 1][c] < n) q.push_back(nx[j + 1][c]);
            }
            sort(p.begin(), p.end(), greater<int>());
            sort(q.begin(), q.end());

            int m1 = p.size(), m2 = q.size();
            for (int d = 1; d <= min(m1, m2); ++d) {
                long long L = p[d - 1] - (d < m1 ? p[d] : -1);
                long long R = (d < m2 ? q[d] : n) - q[d - 1];
                ans += L * R;
            }
        }
        return ans;
    }
};
