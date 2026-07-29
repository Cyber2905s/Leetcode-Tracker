class Solution {
public:
    static bool compare(const pair<pair<int,int>,int>& a,const pair<pair<int,int>,int>& b){
            if(a.first.first!=b.first.first){
                return a.first.first<b.first.first;
            }
            return a.second<b.second;
        }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<pair<int,int>,int>> meets(n);
        for(int i =0;i<n;i++){
            meets[i] = {{intervals[i][1],intervals[i][0]},i+1};
        }
        sort(meets.begin(),meets.end(),compare);
        vector<int> meetings;
        meetings.push_back(meets[0].second);
        int time = meets[0].first.first;
        int cnt = 1;
        for(int i=1;i<n;i++){
            if(time<=meets[i].first.second){
                time = meets[i].first.first;
                meetings.push_back(meets[i].second);
                cnt+=1;
            }
        }
        return n-cnt;
    }
};
