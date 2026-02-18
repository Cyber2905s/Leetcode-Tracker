class Solution {
public:
    int characterReplacement(string s, int k) {
        int n= s.size();
        int l=0,r=0;
        int maxf=0;
        int maxl=0;
        vector <int>hashm (26,0);
        while(r<n){
            hashm[s[r]-'A']++;
            maxf= max(maxf,hashm[s[r]-'A']);
            if((r-l+1)-maxf > k){
                hashm[s[l]-'A']--;
                maxf=0;
                l++;
            }
            if((r-l+1)-maxf <= k){
                maxl= max(r-l+1,maxl);
            }
            r++;
        }
        return maxl;
    }
};
