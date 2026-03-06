class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.empty()) return s;
        string rev= s;
        reverse(rev.begin(),rev.end());
        string temp = s+"#"+rev;
        vector<int> lps(temp.length(),0);
        int i=1;
        int len=0;
        while(i<temp.length()){
            if(temp[i]==temp[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len>0){
                    len=lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        int llen=lps.back();
        string sadd= rev.substr(0,s.length()-llen);
        return sadd+s;
    }
};
