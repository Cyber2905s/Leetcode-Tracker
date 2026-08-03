class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        solve(0,s,ans,path);
        return ans;
    }

    void solve(int ind,string s,vector<vector<string>> &ans,vector<string> &path){
        if(ind==s.size()){
            ans.push_back(path);
            return;
        }
        for(int i =ind;i<s.size();i++){
            if(isPal(s,ind,i)){
                path.push_back(s.substr(ind,i-ind+1));
                solve(i+1,s,ans,path);
                path.pop_back();
            }
        }
    }

    bool isPal(string s,int start,int end){
        while(start<=end){
            if(s[start]==s[end]){
                start++;
                end--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
