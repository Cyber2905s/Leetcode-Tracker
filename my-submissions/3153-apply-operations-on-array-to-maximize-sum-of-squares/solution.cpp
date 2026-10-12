class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        vector<int> bitCount(31, 0);
        for (int x : nums) {
            for (int b = 0; b < 31; b++) {
                if ((x >> b) & 1) {
                    bitCount[b]++;
                }
            }
        }
        long long ans = 0;
        for (int step = 0; step < k; step++) {
            long long currentNum = 0;
            for (int b = 0; b < 31; b++) {
                if (bitCount[b] > 0) {
                    currentNum |= (1LL << b);
                    bitCount[b]--;
                }
            }
            ans = (ans + currentNum * currentNum) % MOD;
        }
        return ans;
    }
};
