class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int left = n;
        vector<int> free(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(fruits[i]<=baskets[j] && free[j]==1){
                    free[j] = 0;
                    left--;
                    break;
                }
            }
        }
        return left;
    }
};
