class Solution {
private:
    void dfs(int row,int col,vector<vector<int>> &image,vector<vector<int>> &ans,int color,int n,int m,int iniCol){
        ans[row][col]=color;
        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow = row+drow[i];
            int ncol = col+dcol[i];
            if(ncol>=0 && ncol<m && nrow>=0 && nrow<n && image[nrow][ncol]==iniCol && ans[nrow][ncol]!=color){
                dfs(nrow,ncol,image,ans,color,n,m,iniCol);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniCol = image[sr][sc];
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> ans = image;
        dfs(sr,sc,image,ans,color,n,m,iniCol);
        return ans;
    }
};
