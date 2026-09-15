class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int maxi = -1e9;
        for(char c:s){
            maxi = max(depth,maxi);
            if(c=='('){
                depth++;
            }
            else if(c==')'){
                depth--;
            }
        }
        return maxi;
    }
};
