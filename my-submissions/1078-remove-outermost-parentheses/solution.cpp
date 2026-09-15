class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        int depth = 0;
        string ans = "";
        for(int i=0;i<n;i++){
            if(s[i]=='(' && depth == 0){
                depth++;
            }
            else if(s[i]=='('){
                ans+=s[i];
                depth++;
            }
            else if(s[i]==')' && depth == 1){
                depth--;
            }
            else if(depth>1 && s[i]==')'){
                ans+=s[i];
                depth--;
            }
        }
        return ans;
    }
};
