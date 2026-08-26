class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for(char ch: expression){
            if(ch==','){
                continue;
            }
            if(ch!=')'){
                st.push(ch);
            }
            else{
                bool hasT = false;
                bool hasF = false;
                while(st.top()!='('){
                    char val = st.top();
                    st.pop();
                    if(val=='t') hasT = true;
                    if(val=='f') hasF = true;
                }
                st.pop();
                char op = st.top();
                st.pop();
                if(op=='!'){
                    st.push(hasT ? 'f':'t');
                }
                else if(op=='&'){
                    st.push(hasF ? 'f':'t');
                }
                else if(op=='|'){
                    st.push(hasT ? 't':'f');
                }
            }
        }
        return st.top()=='t';
    }
};
