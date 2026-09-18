class Solution {
private:
    int cnt(int r, int c, vector<vector<char>>& board,int n, int m){
        int count = 0;
        for(int dr=-1;dr<=1;dr++){
            for(int dc=-1;dc<=1;dc++){
                if(dr==0 && dc==0) continue;
                int nr = dr+r;
                int nc = dc+c;
                if(nr>=0 && nr<n && nc>=0 && nc<m && board[nr][nc]=='M'){
                    count++;
                }
            }
        }
        return count;
    }
    void dfs(int r, int c, vector<vector<char>>& board,int n, int m){
        if(r<0 || r>=n || c<0 || c>=m || board[r][c]!='E'){
            return;
        }
        int mines = cnt(r,c,board,n,m);
        if(mines>0){
            board[r][c] = mines+'0';
        }
        else{
            board[r][c] = 'B';
            for(int dr=-1;dr<=1;dr++){
                for(int dc=-1;dc<=1;dc++){
                    if(dr==0 && dc==0) continue;
                    dfs(r+dr,c+dc,board,n,m);
                }
            }
        }
    }
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        vector<vector<char>> ans = board;
        int n = board.size();
        int m = board[0].size();
        int r = click[0];
        int c = click[1];
        if(board[r][c]=='M'){
            ans[r][c] = 'X';
            return ans;
        }
        dfs(r,c,ans,n,m);
        return ans;
    }
};
