class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> arr(n);
        vector<int> dep(n);
        for(int i=0;i<n;i++){
            arr[i] = intervals[i][0];
            dep[i] = intervals[i][1];
        }
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int i = 0;
        int j = 0;
        int count = 0;
        int maxi = INT_MIN;
        while(i<n){
            if(arr[i]<=dep[j]){
                i++;
                count++;
            }
            else{
                j++;
                count--;
            }
            maxi = max(maxi,count);
        }
        return maxi;
    }
};
