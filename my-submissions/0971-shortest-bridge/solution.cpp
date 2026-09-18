class Solution {
private:
    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& vis,int n){
        vis[r][c]=1;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc]==1){
                dfs(nr,nc,grid,vis,n);
            }
        }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        bool found = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(i,j,grid,vis,n);
                    found = true;
                    break;
                }
            }
            if(found) break;
        }
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        int steps = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int j=0;j<4;j++){
                    int nr = r+dr[j];
                    int nc = c+dc[j];
                    if(nr>=0 && nr<n && nc>=0 && nc<n){
                        if(!vis[nr][nc] && grid[nr][nc]==0){
                            vis[nr][nc] = 1;
                            q.push({nr,nc});
                        }
                        if(!vis[nr][nc] && grid[nr][nc]==1){
                            return steps;
                        }
                    }
                }
            }
            steps++;
        }
        return 0;
    }
};
