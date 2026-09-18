class Solution {
private:
    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<int>>& o, int n, int m){
        o[r][c] = 1;;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !o[nr][nc] && heights[nr][nc]>=heights[r][c]){
                dfs(nr,nc,heights,o,n,m);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> p(n,vector<int>(m,0));
        vector<vector<int>> a(n,vector<int>(m,0));
        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            if(!p[0][i]){
                dfs(0,i,heights,p,n,m);
            }
            if(!a[n-1][i]){
                dfs(n-1,i,heights,a,n,m);
            }
        }
        for(int i=0;i<n;i++){
            if(!p[i][0]){
                dfs(i,0,heights,p,n,m);
            }
            if(!a[i][m-1]){
                dfs(i,m-1,heights,a,n,m);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(p[i][j] && a[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
