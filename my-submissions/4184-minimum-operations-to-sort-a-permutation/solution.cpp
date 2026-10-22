class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int p = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                p = i;
                break;
            }
        }

        // Check if cyclic increasing
        bool is_inc = true;
        for (int i = 0; i < n; ++i) {
            if (nums[(p + i) % n] != i) {
                is_inc = false;
                break;
            }
        }

        if (is_inc) {
            if (p == 0) return 0;
            // Left shifts: p
            // Right shifts via 2 reverses: (n - p) + 2
            return min(p, n - p + 2);
        }

        // Check if cyclic decreasing
        bool is_dec = true;
        for (int i = 0; i < n; ++i) {
            if (nums[(p - i + n) % n] != i) {
                is_dec = false;
                break;
            }
        }

        if (is_dec) {
            // Reverse then left shift
            int op1 = 1 + (n - 1 - p);
            // Left shift then reverse
            int op2 = 1 + (p + 1) % n;
            return min(op1, op2);
        }

        return -1;
    }
};
