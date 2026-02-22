class Solution {
public:
    int binaryGap(int n) {
        int ans=0;
        int pos=0;
        int lpos=-1;
        while(n>0){
            if((n&1)==1){
                if(lpos!=-1){
                    ans = max(ans, abs(pos-lpos));
                    lpos=pos;
                }
                else{
                    lpos=pos;
                }
            }
            n=n>>1;
            pos++;
        }
        return ans;
    }
};
