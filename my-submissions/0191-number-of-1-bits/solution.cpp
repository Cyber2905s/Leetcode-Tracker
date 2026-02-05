class Solution {
public:
    int hammingWeight(int n) {
        int count=0;
        while(n!=0){
            n=n&(n-1);
            count++;
        }
        /* using the divide by 2 approach
        while(n>1){
            count += n&1;
            n=n>>1;
        }
        if(n==1){
            count=count+1;
        }
        */
        return count;
    }
};
