class Solution {
public:
    int countPrimes(int n) {
        if(n<=2){
            return 0;
        }
        vector<bool> isP(n,true);
        isP[0]=false;
        isP[1]=false;
        int cnt=0;
        for(int i=2;i<n;i++){
            if(isP[i]){
                ++cnt;
                for(long long j= (long long)i*i;j<n;j=j+i){
                    isP[j]=false;
                }
            }
        }
        return cnt;
    }
};
