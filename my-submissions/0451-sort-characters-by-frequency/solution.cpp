class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        priority_queue<pair<int,char>> pq;
        string ans = "" ;
        for(const auto& [ch,cnt]:freq){
            pq.push({cnt,ch});
        }
        while(!pq.empty()){
            auto [cnt,ch] = pq.top();
            pq.pop();
            ans.append(cnt,ch);
        }
        return ans;
    }
};
