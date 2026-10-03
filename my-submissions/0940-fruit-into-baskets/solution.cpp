class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0;
        unordered_map<int,int> count;
        int maxi = 0;
        for(int r=0;r<n;r++){
            count[fruits[r]]++;
            while(count.size()>2){
                count[fruits[l]]--;
                if(count[fruits[l]]==0){
                    count.erase(fruits[l]);
                }
                l++;
            }
            maxi = max(maxi,r-l+1);
        }
        return maxi;
    }
};
