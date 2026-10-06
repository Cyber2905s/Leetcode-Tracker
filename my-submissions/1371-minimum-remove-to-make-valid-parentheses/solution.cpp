class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string temp = "";
        int open = 0;
        int close = 0;
        for(char c:s){
            if(c=='('){
                open++;
                temp+=c;
            }
            else if(c==')'){
                if(open>0){
                    temp+=c;
                    open--;
                }
            }
            else{
                temp+=c;
            }
        }
        string ans = "";
        for(int i=temp.size()-1;i>=0;i--){
            if(temp[i]=='(' && open>0){
                open--;
            }
            else{
                ans+=temp[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
