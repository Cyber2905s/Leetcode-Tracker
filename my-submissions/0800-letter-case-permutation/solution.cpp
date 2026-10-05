class Solution {
private:
    void gen(int ind,vector<string>& ans,string& s){
        if(ind==s.size()){
            ans.push_back(s);
            return;
        }
        if(s[ind]>='0' && s[ind]<='9'){
            gen(ind+1,ans,s);
        }
        else{
            s[ind] = toupper(s[ind]);
            gen(ind+1,ans,s);
            s[ind] = tolower(s[ind]);
            gen(ind+1,ans,s);
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        gen(0,ans,s);
        return ans;
    }
};
