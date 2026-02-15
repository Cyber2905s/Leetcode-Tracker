class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n= fruits.size();
        int l=0;
        int maxi=0;
        int dcount=0;
        vector<int> freq(n,0);
        for(int r=0;r<n;r++){
            if(freq[fruits[r]]==0){
                dcount++;
            }
            freq[fruits[r]]++;
            while(dcount>2){
                freq[fruits[l]]--;
                if(freq[fruits[l]]==0){
                    dcount--;
                }
                l++;
            }
            maxi=max(maxi,(r-l+1));
        }
        return maxi;
    }
};
