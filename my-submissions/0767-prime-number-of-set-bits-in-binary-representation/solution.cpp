class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int i=left;i<=right;i++){
            int count =0;
            int a;
            a=i;
            while(a>=1){
                int bit;
                bit = a&1;
                a = a>>1;
                if(bit==1){
                    count++;
                }
            }
            if(prime(count)){
                ans++;
            }
        }
        return ans;
    }
    bool prime(int n){
        if(n<=1){return false;}
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    } 
};
