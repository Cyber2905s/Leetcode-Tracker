class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int n = special.size();
        int maxi = 0;
        maxi = max(maxi,special[0]-bottom);
        maxi = max(maxi,top-special[n-1]);
        for(int i=1;i<n;i++){
            maxi = max(maxi,special[i]-special[i-1]-1);
        }
        return maxi;
    }
};
