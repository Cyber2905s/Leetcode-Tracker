class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        // dp[i] = min cost to reach step i
        // 0-indexed: step 0 has cost 0, costs is 1-indexed so costs[j - 1] corresponds to step j
        vector<long long> dp(n + 1, 0);
        dp[0] = 0;

        for (int j = 1; j <= n; ++j) {
            long long min_prev = -1;

            // Check possible predecessor steps: j - 1, j - 2, j - 3
            for (int step = 1; step <= 3; ++step) {
                int i = j - step;
                if (i >= 0) {
                    long long candidate = dp[i] + (long long)step * step;
                    if (min_prev == -1 || candidate < min_prev) {
                        min_prev = candidate;
                    }
                }
            }

            dp[j] = costs[j - 1] + min_prev;
        }

        return dp[n];
    }
};
