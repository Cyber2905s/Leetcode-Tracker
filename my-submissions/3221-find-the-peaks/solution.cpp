class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        vector<int> ans;
        int n = mountain.size();
        int i = 1;
        while(i<n-1){
            if(mountain[i]>mountain[i-1] && mountain[i]>mountain[i+1]){
                ans.push_back(i);
                i+=2;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};
