class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        for(auto &s:strs){
            vector<int>count(26,0);
            for(auto &ch: s){
                count[ch-'a']++;
            }
            string key="";
            for(int num:count){
                key+=to_string(num)+"#";
            }
            map[key].push_back(s);
        }
        vector<vector<string>> ans;
        for(const auto &it: map){
            ans.push_back(it.second);
        }
        return ans;
    }
};
