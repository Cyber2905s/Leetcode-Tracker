class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int result=0;
        int sign=1;
        long long num=0;
        for(int i=0;i<s.length();i++){
            char c = s[i];
            if(isdigit(c)){
                num = (num * 10) + (c-'0');
            }
            else if(c=='+'){
                result += sign*num;
                sign =1;
                num=0;
            }
            else if(c=='-'){
                result += sign*num;
                sign =-1;
                num=0;
            }
            else if(c=='('){
            st.push(result);
            st.push(sign);
            result =0;
            num=0;
            sign=1;
            }
            else if(c==')'){
                result += sign*num;
                num=0;
                result *= st.top();
                st.pop();
                result += st.top();
                st.pop();
            }
        }
        result += sign*num;
        return result;
    }
};
