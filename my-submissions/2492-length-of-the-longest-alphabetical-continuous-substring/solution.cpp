class Solution {
public:
    int longestContinuousSubstring(string s) {
        if(s.size()==1) return 1;
        int maxi = 0;
        int len = 1;
        for(int i=1;i<s.size();i++){
            if((s[i]-'a')-(s[i-1]-'a')==1){
                len++;
            }
            else{
                len = 1;
            }
            maxi = max(maxi,len);
        }
        return maxi;
    }
};
