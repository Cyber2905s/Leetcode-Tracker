class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long ans = 0;
        
        int even_count = 1; // Empty prefix sum = 0 is even
        int odd_count = 0;
        int prefix_sum = 0;
        
        for (int num : arr) {
            prefix_sum += num;
            
            if (prefix_sum % 2 == 1) {
                // Odd prefix sum minus any previous even prefix sum = odd subarray sum
                ans = (ans + even_count) % MOD;
                odd_count++;
            } else {
                // Even prefix sum minus any previous odd prefix sum = odd subarray sum
                ans = (ans + odd_count) % MOD;
                even_count++;
            }
        }
        
        return ans;
    }
};
