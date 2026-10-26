class Solution {
private:
    void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis,int n,int m,long long& sum){
        vis[row][col]=1;
        sum+=grid[row][col];
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr = row+drow[i];
            int nc = col+dcol[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]>0 && !vis[nr][nc]){
                dfs(nr,nc,grid,vis,n,m,sum);
            }
        } 
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0 && !vis[i][j]){
                    long long sum = 0;
                    dfs(i,j,grid,vis,n,m,sum);
                    if(sum%k==0){
                        ans+=1;
                    }
                }
            }
        }
        return ans;
    }
};
