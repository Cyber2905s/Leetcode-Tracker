class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int cnt =0;
        int clen=1,plen=0;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                clen++;
            }
            else{
                cnt+=min(clen,plen);
                plen=clen;
                clen=1;
            }
        }
        cnt+=min(clen,plen);
        return cnt;
    }
};
