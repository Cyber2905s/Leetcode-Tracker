class Solution {
public:
    int differenceOfSums(int n, int m) {
        vector<int> div;
        vector<int> ndiv;
        int sum1=0;
        int sum2=0;
        for(int i=1;i<=n;i++){
            if(i%m!=0){
                ndiv.push_back(i);
            }
            if(i%m==0){
                div.push_back(i);
            }
        }
        for(int i=0;i<ndiv.size();i++){
            sum1+=ndiv[i];
        }
        for(int i=0;i<div.size();i++){
            sum2+=div[i];
        }
        return (sum1-sum2);
    }
};
