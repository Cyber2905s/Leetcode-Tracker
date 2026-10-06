class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int close = 0;
        int n = s.size();
        int i = 0;
        int ans = 0;
        while(i<n){
            if(s[i]=='('){
                open++;
            }
            else{
                if(i+1<n && s[i+1]==')'){
                    i++;
                }
                else{
                    ans++;
                }
                if(open>0){
                    open--;
                }
                else{
                    ans++;
                }
            }
            i++;
        }
        ans+=(2*open);
        return ans;
    }
};
