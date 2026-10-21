class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        if (n <= 1) return 0;
        if (is_sorted(s.begin(), s.end())) return 0;
        if (n == 2) return -1;

        string sorted_s = s;
        sort(sorted_s.begin(), sorted_s.end());

        int l = 0;
        while (l < n && s[l] == sorted_s[l]) {
            l++;
        }

        int r = n - 1;
        while (r >= 0 && s[r] == sorted_s[r]) {
            r--;
        }

        // Can be sorted in 1 operation if the mismatched range length < n
        if (r - l + 1 < n) {
            return 1;
        }

        char min_char = sorted_s[0];
        char max_char = sorted_s[n - 1];

        // Check if min_char appears anywhere in s[0 ... n-2]
        bool min_in_prefix = false;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == min_char) {
                min_in_prefix = true;
                break;
            }
        }

        // Check if max_char appears anywhere in s[1 ... n-1]
        bool max_in_suffix = false;
        for (int i = 1; i < n; ++i) {
            if (s[i] == max_char) {
                max_in_suffix = true;
                break;
            }
        }

        // If at least one boundary can be fixed in step 1, 2 operations suffice
        if (min_in_prefix || max_in_suffix) {
            return 2;
        }

        // Otherwise, min is stuck at the end and max is stuck at the beginning
        return 3;
    }
};
