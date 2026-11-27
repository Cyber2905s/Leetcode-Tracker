class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        const int MAX_F = 1500;
        
        // Step 1: Count frequency of each factor in O(n)
        vector<int> freq(MAX_F + 1, 0);
        for (int i = 0; i < n; i++) {
            freq[items[i][0]]++;
        }
        
        // Step 2: Precompute how many multiples each factor f has (excluding itself)
        vector<int> multiples_count(MAX_F + 1, 0);
        for (int f = 1; f <= MAX_F; f++) {
            if (freq[f] == 0) continue;
            for (int mult = f; mult <= MAX_F; mult += f) {
                multiples_count[f] += freq[mult];
            }
            multiples_count[f] -= 1; // Exclude item i itself (j != i)
        }
        
        // dp[b] = max total copies obtainable with cost <= b
        vector<int> dp(budget + 1, 0);
        
        for (int i = 0; i < n; i++) {
            int f = items[i][0];
            int p = items[i][1];
            if (p > budget) continue;
            
            int first_copy_val = 1 + multiples_count[f];
            
            // 1. 0/1 Knapsack pass (backwards): take 1st copy with free bonus
            for (int b = budget; b >= p; b--) {
                dp[b] = max(dp[b], dp[b - p] + first_copy_val);
            }
            
            // 2. Unbounded Knapsack pass (forwards): take additional copies (+1 each)
            for (int b = p; b <= budget; b++) {
                dp[b] = max(dp[b], dp[b - p] + 1);
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};
