class Solution {
public:
    bool isBalanced(string num) {
        int n = num.size();
        int even = 0;
        int odd = 0;
        for(int i=0;i<n;i++){
            if(i%2==0) even+=(num[i]-'0');
            else{
                odd+=(num[i]-'0');
            }
        }
        return odd==even;
    }
};
