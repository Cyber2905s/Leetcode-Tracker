class Solution {
public:
    vector<string> pad = {
        "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
    };
    vector<string> letterCombinations(string digits) {
        int n= digits.length();
        vector<string> ans;
        string str;
        back(ans,str,digits,0);
        return ans;
    }
    void back(vector<string>& ans,string& str,string& dig,int ind){
        if(ind==dig.length()){
            ans.push_back(str);
            return;
        }
        int digit = dig[ind]-'0';
        string s=pad[digit];
        for(char letter: s){
            str.push_back(letter);
            back(ans,str,dig,ind+1);
            str.pop_back();
        }
    }
};
