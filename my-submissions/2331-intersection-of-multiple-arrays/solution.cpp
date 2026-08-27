class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int freq[1001] = {0};
        int n = nums.size();
        for(const auto& rows: nums){
            for(const auto& num: rows){
                freq[num]++;
            }
        }
        vector<int> ans;
        for(int i=1;i<=1000;i++){
            if(freq[i]==n){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
