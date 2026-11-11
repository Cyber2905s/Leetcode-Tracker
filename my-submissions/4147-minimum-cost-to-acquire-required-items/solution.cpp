class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = cost1, c2 = cost2, c3 = costBoth;
        long long n1 = need1, n2 = need2;

        // Ensure n1 <= n2 for simplicity
        if (n1 > n2) {
            swap(n1, n2);
            swap(c1, c2);
        }

        // Option 1: Buy only separate items
        long long opt1 = n1 * c1 + n2 * c2;

        // Option 2: Buy n1 type-3 items, and (n2 - n1) type-2 items
        long long opt2 = n1 * c3 + (n2 - n1) * c2;

        // Option 3: Buy n2 type-3 items (satisfying both completely)
        long long opt3 = n2 * c3;

        return min({opt1, opt2, opt3});
    }
};
