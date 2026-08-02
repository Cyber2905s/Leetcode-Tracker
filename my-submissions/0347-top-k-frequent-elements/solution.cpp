class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int num: nums){
            map[num]++;
        }
        vector<pair<int,int>> count;
        for(auto &it: map){
            count.push_back({it.second,it.first});
        }
        vector<int> ans;
        sort(count.begin(),count.end(),greater<pair<int,int>>());
        for(int i=0;i<k;i++){
            ans.push_back(count[i].second);
        }
        return ans;
    }
};
