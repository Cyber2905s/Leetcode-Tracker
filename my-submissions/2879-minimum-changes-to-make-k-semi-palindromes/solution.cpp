class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;
        
        // cost[i][j] = min changes to make s[i..j] a semi-palindrome
        vector<vector<int>> cost(n, vector<int>(n, INF));
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) { // length >= 2 required
                int len = j - i + 1;
                
                // Try all proper divisors d of len (1 <= d < len)
                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;
                    
                    int changes = 0;
                    int group_len = len / d;
                    
                    // Check each of the d interleaved groups
                    for (int rem = 0; rem < d; rem++) {
                        int left = 0, right = group_len - 1;
                        while (left < right) {
                            if (s[i + rem + left * d] != s[i + rem + right * d]) {
                                changes++;
                            }
                            left++;
                            right--;
                        }
                    }
                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }
        
        // dp[p][i] = min changes to split prefix s[0..i-1] into p semi-palindromes
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INF));
        dp[0][0] = 0;
        for (int p = 1; p <= k; p++) {
            for (int i = 2 * p; i <= n; i++) { // each part needs length >= 2
                for (int j = 2 * (p - 1); j <= i - 2; j++) {
                    if (dp[p - 1][j] != INF) {
                        dp[p][i] = min(dp[p][i], dp[p - 1][j] + cost[j][i - 1]);
                    }
                }
            }
        }
        
        return dp[k][n];
    }
};
