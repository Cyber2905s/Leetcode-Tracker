class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char,char> cto = {
            {')','('},
            {'}','{'},
            {']','['}
        };
        for(char c: s){
            if(cto.count(c)){
                if(!stack.empty() && stack.top()==cto[c]){
                    stack.pop();
                }
                else{
                    return false;
                }
            }
            else{
                stack.push(c);
            }
        }
        return stack.empty();
    }
};
