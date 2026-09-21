class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> count(k, 0);
        for (int x : nums) {
            vector<long long> nextCount(k, 0);
            int currentRem = x % k;
            nextCount[currentRem] += 1;
            for (int r = 0; r < k; r++) {
                if (count[r] > 0) {
                    int newRem = (r * currentRem) % k;
                    nextCount[newRem] += count[r];
                }
            }
            for (int r = 0; r < k; r++) {
                result[r] += nextCount[r];
            }
            count = nextCount;
        }
        return result;
    }
};
