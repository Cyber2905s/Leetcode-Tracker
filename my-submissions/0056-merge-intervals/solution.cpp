class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        int n = intervals.size();
        for(int i=1;i<n;i++){
            int currentStart = intervals[i][0];
            int currentEnd = intervals[i][1];
            int lastIntervalEnd = res.back()[1];
            if (currentStart > lastIntervalEnd) {
                res.push_back(intervals[i]);
            }
            else {
                res.back()[1] = max(lastIntervalEnd, currentEnd);
            }
        }
        return res;
    }
};
