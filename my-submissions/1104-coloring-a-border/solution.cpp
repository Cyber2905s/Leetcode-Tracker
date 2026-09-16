class Solution {
private:
    void dfs(int row, int col, int color, vector<vector<int>>& ans,vector<vector<int>>& grid, vector<vector<int>>& vis,int ini,int n,int m){
        vis[row][col] = 1;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        for(int i=0;i<4;i++){
            int r = row+drow[i];
            int c = col+dcol[i];
            if(r<0 || r>=n || c<0 || c>=m || grid[r][c]!=ini){
                ans[row][col] = color;
            }
            else if(!vis[r][c]){
                dfs(r,c,color,ans,grid,vis,ini,n,m);
            }
        }
    }
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n = grid.size();
        int m = grid[0].size();
        int inicol = grid[row][col];
        vector<vector<int>> ans = grid;
        vector<vector<int>> vis(n,vector<int>(m,0));
        dfs(row,col,color,ans,grid,vis,inicol,n,m);
        return ans;
    }
};
