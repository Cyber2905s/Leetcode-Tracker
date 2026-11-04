class Solution {
    multiset<long long> left_set, right_set;
    long long sum_left = 0, sum_right = 0;
    int k_left, k_right; // sizes for left and right sets

    void balance() {
        while (left_set.size() > k_left) {
            auto it = prev(left_set.end());
            long long val = *it;
            left_set.erase(it);
            sum_left -= val;
            right_set.insert(val);
            sum_right += val;
        }
        while (left_set.size() < k_left && !right_set.empty()) {
            auto it = right_set.begin();
            long long val = *it;
            right_set.erase(it);
            sum_right -= val;
            left_set.insert(val);
            sum_left += val;
        }
    }

    void add(long long val) {
        if (left_set.empty() || val <= *left_set.rbegin()) {
            left_set.insert(val);
            sum_left += val;
        } else {
            right_set.insert(val);
            sum_right += val;
        }
        balance();
    }

    void remove(long long val) {
        auto it = left_set.find(val);
        if (it != left_set.end()) {
            left_set.erase(it);
            sum_left -= val;
        } else {
            it = right_set.find(val);
            right_set.erase(it);
            sum_right -= val;
        }
        balance();
    }

    long long get_cost(int x) {
        long long median = *left_set.rbegin();
        if (x % 2 == 0) {
            return sum_right - sum_left;
        } else {
            return (median * (long long)left_set.size() - sum_left) + 
                   (sum_right - median * (long long)right_set.size());
        }
    }

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        k_left = (x + 1) / 2;
        k_right = x / 2;

        vector<long long> window_cost(n, 0);

        // Compute cost for every window of size x
        for (int i = 0; i < n; ++i) {
            add(nums[i]);
            if (i >= x) {
                remove(nums[i - x]);
            }
            if (i >= x - 1) {
                window_cost[i] = get_cost(x);
            }
        }

        const long long INF = 1e16;
        // dp[j][i] = min cost to select j subarrays within nums[0...i]
        vector<long long> prev_dp(n, 0);
        vector<long long> curr_dp(n, INF);

        for (int j = 1; j <= k; ++j) {
            fill(curr_dp.begin(), curr_dp.end(), INF);
            for (int i = j * x - 1; i < n; ++i) {
                // Option 1: Do not pick a subarray ending at i
                curr_dp[i] = curr_dp[i - 1];

                // Option 2: Pick a subarray ending at i
                long long prev_val = (i - x >= 0) ? prev_dp[i - x] : 0;
                if (prev_val != INF) {
                    curr_dp[i] = min(curr_dp[i], prev_val + window_cost[i]);
                }
            }
            prev_dp = curr_dp;
        }

        return curr_dp[n - 1];
    }
};
