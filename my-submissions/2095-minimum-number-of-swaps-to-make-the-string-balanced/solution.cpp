class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int open = 0;
        int count = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='['){
                open++;
            }
            else{
                if(open>0) open--;
                else if(open==0) count++;
            }
        }
        return (count+1)/2;
    }
};
