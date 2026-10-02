class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        func(ans,0,0,"",n);
        return ans;
    }

    void func(vector<string> &ans,int open,int close,string s,int n){
        if(s.length()==2*n){
            ans.push_back(s);
            return;
        }
        if(open<n){
            func(ans,open+1,close,s+'(',n);
        }
        if(close<open){
            func(ans,open,close+1,s+')',n);
        }
    }
};
