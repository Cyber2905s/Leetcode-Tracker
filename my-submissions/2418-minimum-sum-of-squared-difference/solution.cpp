class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        int k = k1 + k2;
        int maxDiff = 0;

        vector<int> diff(n);
        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, diff[i]);
        }

        if (maxDiff == 0) return 0;

        vector<int> count(maxDiff + 1, 0);
        for (int i = 0; i < n; i++) {
            count[diff[i]]++;
        }

        for (int v = maxDiff; v > 0; v--) {
            if (count[v] == 0) continue;

            if (k >= count[v]) {
                k -= count[v];
                count[v - 1] += count[v];
                count[v] = 0;
            } else {
                count[v - 1] += k;
                count[v] -= k;
                k = 0;
                break;
            }
        }

        long long ans = 0;
        for (long long v = 1; v <= maxDiff; v++) {
            if (count[v] > 0) {
                ans += (long long)count[v] * (v * v);
            }
        }

        return ans;
    }
};
