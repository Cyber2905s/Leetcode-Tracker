class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(const string& token: tokens){
            if(token == "+" || token == "*" || token == "/" || token == "-" ){
                int r=st.top();
                st.pop();
                int l = st.top();
                st.pop();
                if(token == "+"){
                    st.push(r+l);
                }
                else if(token == "-"){
                    st.push(l-r);
                }
                else if(token == "/"){
                    st.push(l/r);
                }
                else if(token == "*"){
                    st.push(l*r);
                }
            }
            else{
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};
