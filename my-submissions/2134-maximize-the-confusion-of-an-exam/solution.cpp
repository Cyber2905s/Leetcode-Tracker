class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int l = 0;
        int r = 0;
        int maxi = 0;
        int t = 0;
        int f = 0;
        while(r<n){
            if(answerKey[r]=='T'){
                t++;
            }
            else if(answerKey[r]=='F'){
                f++;
            }
            if(t<=k || f<=k){
                maxi = max(maxi,r-l+1);
            }
            if(t>k && f>k){
                if(answerKey[l]=='F') f--;
                else if(answerKey[l]=='T') t--;
                l++;
            }
            r++;
        }
        return maxi;
    }
};
