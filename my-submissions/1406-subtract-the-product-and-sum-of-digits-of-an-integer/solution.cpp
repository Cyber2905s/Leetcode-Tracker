class Solution {
public:
    int subtractProductAndSum(int n) {
        int pro=1;
        int sum=0;
        while(n!=0){
            int temp=n%10;
            sum+=temp;
            pro*=temp;
            n/=10;
        }
        return (pro-sum);
    }
};
