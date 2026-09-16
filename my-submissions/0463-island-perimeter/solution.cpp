class Solution {
private:
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis,int& peri,int n,int m){
        vis[i][j] = 1;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        for(int k=0;k<4;k++){
            int r = i+drow[k];
            int c = j+dcol[k];
            if(r<0 || r>=n || c<0 || c>=m || grid[r][c]==0){
                peri++;
            }
            else if(!vis[r][c]){
                dfs(r,c,grid,vis,peri,n,m);
            }
        }
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int peri = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    dfs(i,j,grid,vis,peri,n,m);
                    return peri;
                }
            }
        }
        return peri;
    }
};
