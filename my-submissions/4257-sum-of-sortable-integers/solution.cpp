class Solution {
private:
    bool isSortable(const vector<int>& nums, int n, int k) {
        int prevMax = -1;

        for (int start = 0; start < n; start += k) {
            int dropCount = 0;
            int dropIdx = -1;

            for (int i = 0; i < k; ++i) {
                int curr = nums[start + i];
                int next = nums[start + (i + 1) % k];
                if (curr > next) {
                    dropCount++;
                    dropIdx = i;
                }
            }

            if (dropCount > 1) {
                return false;
            }

            int blockMin, blockMax;
            if (dropCount == 0) {
                blockMin = nums[start];
                blockMax = nums[start];
            } else {
                blockMin = nums[start + (dropIdx + 1) % k];
                blockMax = nums[start + dropIdx];
            }

            if (prevMax != -1 && prevMax > blockMin) {
                return false;
            }

            prevMax = blockMax;
        }

        return true;
    }

public:
    long long sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        long long totalSum = 0;

        for (int k = 1; k <= n; ++k) {
            if (n % k == 0) {
                if (isSortable(nums, n, k)) {
                    totalSum += k;
                }
            }
        }

        return totalSum;
    }
};
