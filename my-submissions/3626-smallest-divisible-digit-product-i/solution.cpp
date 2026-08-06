class Solution {
public:
    int getpro(int num){
        int pro = 1;
        while(num>0){
            int dig = num%10;
            pro*=dig;
            num/=10;
        }
        return pro;
    }
    int smallestNumber(int n, int t) {
        int curr = n;
        while(true){
            if(getpro(curr)%t==0){
                return curr;
            }
            curr++;
        }
    }
};
