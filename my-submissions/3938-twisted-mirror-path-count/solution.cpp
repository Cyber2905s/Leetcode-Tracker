class Solution {
    const int MOD = 1e9 + 7;
    int m, n;
    
    // memo[r][c][dir] stores {final_r, final_c}
    // dir: 0 = RIGHT, 1 = DOWN
    pair<int, int> memo[505][505][2];
    bool visited[505][505][2];

    pair<int, int> resolve(int r, int c, int dir, const vector<vector<int>>& grid) {
        if (r >= m || c >= n) {
            return {-1, -1}; // Out of bounds
        }
        if (grid[r][c] == 0) {
            return {r, c};
        }
        if (visited[r][c][dir]) {
            return memo[r][c][dir];
        }

        visited[r][c][dir] = true;
        pair<int, int> res;
        if (dir == 0) {
            // Entered moving right -> reflected down into (r + 1, c)
            res = resolve(r + 1, c, 1, grid);
        } else {
            // Entered moving down -> reflected right into (r, c + 1)
            res = resolve(r, c + 1, 0, grid);
        }

        return memo[r][c][dir] = res;
    }

public:
    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                visited[i][j][0] = visited[i][j][1] = false;
            }
        }

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] == 0 || grid[i][j] == 1) continue;

                // 1. Move Right into (i, j + 1)
                pair<int, int> right_dest = resolve(i, j + 1, 0, grid);
                if (right_dest.first != -1) {
                    dp[right_dest.first][right_dest.second] = 
                        (dp[right_dest.first][right_dest.second] + dp[i][j]) % MOD;
                }

                // 2. Move Down into (i + 1, j)
                pair<int, int> down_dest = resolve(i + 1, j, 1, grid);
                if (down_dest.first != -1) {
                    dp[down_dest.first][down_dest.second] = 
                        (dp[down_dest.first][down_dest.second] + dp[i][j]) % MOD;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
