class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string (n,'.'));
        vector<int> left(n,0),updiag(2*n-1,0),lowdiag(2*n-1,0);
        solve(0,board,ans,left,updiag,lowdiag,n);
        return ans;
    }

    void solve(int col,vector<string> &board,vector<vector<string>> &ans,vector<int> &left,vector<int> &updiag,vector<int> &lowdiag,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(left[row]==0 && lowdiag[row+col]==0 && updiag[n-1+col-row]==0){
                board[row][col]='Q';
                left[row]=1;
                lowdiag[row+col]=1;
                updiag[n-1+col-row]=1;
                solve(col+1,board,ans,left,updiag,lowdiag,n);
                board[row][col]='.';
                left[row]=0;
                lowdiag[row+col]=0;
                updiag[n-1+col-row]=0;
            }
        }
    }

    
};
