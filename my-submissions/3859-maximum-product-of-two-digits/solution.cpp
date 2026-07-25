class Solution {
public:
    int maxProduct(int n) {
        int max1=0;
        int max2=0;
        while(n!=0){
            int b = n%10;
            n/=10;
            if(b>=max1){
                max2=max1;
                max1=b;
            }
            else if(b>max2){
                max2=b;
            }
        }
        return max1*max2;
    }
};
