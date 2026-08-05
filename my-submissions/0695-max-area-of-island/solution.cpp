class Solution {
private:
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<int>>& grid,int n,int m,int &count){
        vis[row][col]=1;
        count++;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow = row+drow[i];
            int ncol = col+dcol[i];
            if(ncol>=0 && ncol<m && nrow>=0 && nrow<n && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                dfs(nrow,ncol,vis,grid,n,m,count);
            }
        }

    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    int count = 0;
                    dfs(i,j,vis,grid,n,m,count);
                    ans = max(count,ans);
                }
            }
        }
        return ans;
    }
};
