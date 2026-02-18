class Solution {
public:
    bool hasAlternatingBits(int n) {
        /* normal code with using using loop tc is O(1)
        int lbit;
        int cbit;
        while(n>1){
            lbit = n&1;
            n=n>>1;
            cbit = n&1;
            if(lbit==cbit){
                return false;
            }
        }
        return true; */
        long x = n ^ (n >> 1);
        return (x & (x + 1)) == 0;
    }
};
