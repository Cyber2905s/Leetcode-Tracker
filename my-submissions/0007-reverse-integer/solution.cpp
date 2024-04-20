class Solution {
public:
    int reverse(int x) {
        if(x>INT_MAX || x<INT_MIN){
            return 0;
        }
        int rev=0;
        while(x!=0){
            if(rev >INT_MAX/10 || rev <INT_MIN/10){
                return 0;
            }
            rev=rev*10+(x%10);
            x /= 10;
        }
        return rev;
    }
};
