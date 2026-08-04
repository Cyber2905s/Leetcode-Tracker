class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(search(i,j,n,m,0,board,word)) return true;
                }
            }
        }
        return false;
    }

    bool search(int i,int j,int n,int m,int k,vector<vector<char>> &board,string word){
        if(k==word.size()) return true;
        if(i<0 || j<0 || i==n || j==m || board[i][j]!=word[k]){
            return false;
        }
        char ch = board[i][j];
        board[i][j]='#';
        bool op1 = search(i+1,j,n,m,k+1,board,word);
        bool op2 = search(i,j+1,n,m,k+1,board,word);
        bool op3 = search(i,j-1,n,m,k+1,board,word);
        bool op4 = search(i-1,j,n,m,k+1,board,word);
        board[i][j]=ch;
        return op1||op2||op3||op4;
    }
};
