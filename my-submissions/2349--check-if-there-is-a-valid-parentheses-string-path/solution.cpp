class Solution {
    int memo[100][100][105];
    int m, n;

    bool dfs(int r, int c, int balance, vector<vector<char>>& grid) {
        balance += (grid[r][c] == '(' ? 1 : -1);

        // More ')' than '(' along current path
        if (balance < 0) return false;

        // Remaining steps available to reach (m - 1, n - 1)
        int remainingSteps = (m - 1 - r) + (n - 1 - c);

        // If open brackets exceed remaining steps, we cannot close them all
        if (balance > remainingSteps) return false;

        // Reached destination
        if (r == m - 1 && c == n - 1) {
            return balance == 0;
        }

        if (memo[r][c][balance] != -1) {
            return memo[r][c][balance];
        }

        bool canReach = false;

        // Move Down
        if (r + 1 < m) {
            canReach = canReach || dfs(r + 1, c, balance, grid);
        }

        // Move Right
        if (!canReach && c + 1 < n) {
            canReach = canReach || dfs(r, c + 1, balance, grid);
        }

        return memo[r][c][balance] = canReach;
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // Path length must be even to be valid
        if ((m + n - 1) % 2 != 0) return false;

        // Must start with '(' and end with ')'
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;

        memset(memo, -1, sizeof(memo));

        return dfs(0, 0, 0, grid);
    }
};
