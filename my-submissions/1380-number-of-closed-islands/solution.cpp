class Solution {
private:
    void dfs(int r, int c, const vector<vector<int>>& grid, vector<vector<int>>& vis) {
        vis[r][c] = 1;
        int n = grid.size();
        int m = grid[0].size();
        int row[] = {-1, 0, 1, 0};
        int col[] = {0, 1, 0, -1};
        
        for (int i = 0; i < 4; i++) {
            int nr = r + row[i];
            int nc = c + col[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 0) {
                dfs(nr, nc, grid, vis);
            }
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 0 && !vis[0][i]) {
                dfs(0, i, grid, vis);
            }
            if (grid[n - 1][i] == 0 && !vis[n - 1][i]) {
                dfs(n - 1, i, grid, vis);
            }
        }
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 0 && !vis[i][0]) {
                dfs(i, 0, grid, vis);
            }
            if (grid[i][m - 1] == 0 && !vis[i][m - 1]) {
                dfs(i, m - 1, grid, vis);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0 && !vis[i][j]) {
                    dfs(i, j, grid, vis);
                    ans++;
                }
            }
        }

        return ans;
    }
};
