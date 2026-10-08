class Solution {
public:
    int totalNQueens(int n) {
        vector<int> left(n,0),updiag(2*n-1,0),lowdiag(2*n-1,0);
        return solve(0,n,left,updiag,lowdiag);
    }

    int solve(int col,int n,vector<int> &left,vector<int> &updiag,vector<int> &lowdiag){
        if(col==n){
            return 1;
        }
        int count = 0;
        for(int row=0;row<n;row++){
            if(left[row]==0 && lowdiag[row+col]==0 && updiag[n-1+col-row]==0){
                left[row] = 1;
                lowdiag[row+col] = 1;
                updiag[n-1+col-row] = 1;
                count += solve(col+1,n,left,updiag,lowdiag);
                left[row] = 0;
                lowdiag[row+col] = 0;
                updiag[n-1+col-row] = 0;
            }
        }
        return count;
    }
};
