class Solution {
private:
    int getDigitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    struct Element {
        int digitSum;
        int val;
        int origIdx;
    };

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<Element> elements(n);
        
        for (int i = 0; i < n; ++i) {
            elements[i] = {getDigitSum(nums[i]), nums[i], i};
        }

        sort(elements.begin(), elements.end(), [](const Element& a, const Element& b) {
            if (a.digitSum != b.digitSum) {
                return a.digitSum < b.digitSum;
            }
            return a.val < b.val;
        });

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i] || elements[i].origIdx == i) {
                continue;
            }

            int cycleSize = 0;
            int curr = i;
            while (!visited[curr]) {
                visited[curr] = true;
                curr = elements[curr].origIdx;
                cycleSize++;
            }

            if (cycleSize > 1) {
                swaps += (cycleSize - 1);
            }
        }

        return swaps;
    }
};
