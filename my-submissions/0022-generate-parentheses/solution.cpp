class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        par(ans,0,0,"",n);
        return ans;
    }

    void par(vector<string>& ans, int open,int close,string s, int n){
        if(s.length()==2*n){
            ans.push_back(s);
            return;
        }
        if(open<n){
            par(ans,open+1,close,s+"(",n);
        }
        if(close<open){
            par(ans,open,close+1,s+")",n);
        }
    }
};
