class Solution {
private:
    int me(vector<vector<int>>& mat,int n,int m,int col){
        int maxi = -1e9;
        int row = -1;
        for(int i=0;i<n;i++){
            if(maxi<mat[i][col]){
                maxi = mat[i][col];
                row = i;
            }
        }
        return row; 
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int l = 0;
        int h = m-1;
        while(l<=h){
            int mid = l+(h-l)/2;
            int row = me(mat,n,m,mid);
            int left = mid-1>=0 ? mat[row][mid-1] : -1;
            int right = mid+1<m ? mat[row][mid+1] : -1;
            if(mat[row][mid]>left && mat[row][mid]>right){
                return {row,mid};
            }
            else if(mat[row][mid]<left) h = mid-1;
            else l = mid+1;
        }
        return {-1,-1};
    }
};
