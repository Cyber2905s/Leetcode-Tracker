class Solution {
public:
    bool checkDivisibility(int n) {
        int num = n;
        int sum = 0;
        int pro = 1;
        while(num>0){
            int dig = num%10;
            sum+=dig;
            pro*=dig;
            num/=10;
        }
        return (n%(sum+pro)==0);
    }
};
