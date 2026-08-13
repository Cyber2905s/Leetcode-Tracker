class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n,vector<int>(n,1e9));
        for(auto it: edges){
            mat[it[0]][it[1]]=it[2];
            mat[it[1]][it[0]]=it[2];
        }
        for(int i=0;i<n;i++){
            mat[i][i]=0;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(mat[i][k]!=1e9 && mat[k][j]!=1e9){
                        mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
                    }
                }
            }
        }
        int cityCount = n;
        int cityNum = -1;
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(mat[i][j]<=distanceThreshold){
                    cnt++;
                }
            }
            if(cnt<=cityCount){
                cityCount = cnt;
                cityNum = i;
            }
        }
        return cityNum;
    }
};
