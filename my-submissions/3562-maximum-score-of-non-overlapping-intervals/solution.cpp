class Solution {
    struct Interval {
        int l, r, weight, id;
    };

    struct State {
        long long weight = -1;
        int len = 0;
        int idx[4] = {-1, -1, -1, -1};
    };

    // Returns true if State 'a' is strictly preferred over State 'b'
    static bool isBetter(const State& a, const State& b) {
        if (a.weight == -1) return false;
        if (b.weight == -1) return true;
        if (a.weight != b.weight) {
            return a.weight > b.weight;
        }
        int minLen = min(a.len, b.len);
        for (int i = 0; i < minLen; ++i) {
            if (a.idx[i] != b.idx[i]) {
                return a.idx[i] < b.idx[i];
            }
        }
        return a.len < b.len;
    }
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Interval> arr(n + 1);
        for (int i = 0; i < n; ++i) {
            arr[i + 1] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }

        // Sort intervals primarily by end time 'r' ascending
        sort(arr.begin() + 1, arr.end(), [](const Interval& a, const Interval& b) {
            if (a.r != b.r) return a.r < b.r;
            if (a.l != b.l) return a.l < b.l;
            return a.id < b.id;
        });

        // Flattened DP table of size (n + 1) * 5: dp[i * 5 + k] represents dp[i][k]
        vector<State> dp((n + 1) * 5);

        // Base case: choosing 0 intervals yields 0 weight
        for (int i = 0; i <= n; ++i) {
            dp[i * 5 + 0].weight = 0;
            dp[i * 5 + 0].len = 0;
        }

        for (int i = 1; i <= n; ++i) {
            // Binary search to find the latest interval j < i such that arr[j].r < arr[i].l
            int l = 1, h = i - 1, j = 0;
            while (l <= h) {
                int mid = l + (h - l) / 2;
                if (arr[mid].r < arr[i].l) {
                    j = mid;
                    l = mid + 1;
                } else {
                    h = mid - 1;
                }
            }

            for (int k = 1; k <= 4; ++k) {
                // Option A: Skip interval i
                State bestK = dp[(i - 1) * 5 + k];

                // Option B: Take interval i (combine with dp[j][k - 1])
                const State& prev = dp[j * 5 + (k - 1)];
                if (prev.weight != -1) {
                    State take;
                    take.weight = prev.weight + arr[i].weight;
                    take.len = k;

                    // Insert arr[i].id into the already-sorted array of indices
                    int p = 0;
                    bool inserted = false;
                    int curId = arr[i].id;
                    for (int m = 0; m < k - 1; ++m) {
                        if (!inserted && curId < prev.idx[m]) {
                            take.idx[p++] = curId;
                            inserted = true;
                        }
                        take.idx[p++] = prev.idx[m];
                    }
                    if (!inserted) {
                        take.idx[p++] = curId;
                    }

                    if (isBetter(take, bestK)) {
                        bestK = take;
                    }
                }

                dp[i * 5 + k] = bestK;
            }
        }

        // Identify the best configuration among choosing 1 to 4 intervals
        State best;
        for (int k = 1; k <= 4; ++k) {
            if (dp[n * 5 + k].weight != -1) {
                if (isBetter(dp[n * 5 + k], best)) {
                    best = dp[n * 5 + k];
                }
            }
        }

        vector<int> result;
        for (int m = 0; m < best.len; ++m) {
            result.push_back(best.idx[m]);
        }
        return result;
    }
};
