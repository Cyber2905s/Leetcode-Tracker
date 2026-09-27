class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        vector<char> st;
        for(char c:s){
            if(c==')'){
                string temp = "";
                while(!st.empty() && st.back()!='('){
                    temp+=st.back();
                    st.pop_back();
                }
                st.pop_back();
                for(char c:temp){
                    st.push_back(c);
                }
            }
            else{
                st.push_back(c);
            }
        }
        return string(st.begin(),st.end());
    }
};
