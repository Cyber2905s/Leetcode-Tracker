class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = *min_element(nums.begin(),nums.end());
        int maxi = *max_element(nums.begin(),nums.end());
        unordered_set<int> set(nums.begin(),nums.end());
        vector<int> ans;
        for(int i=mini;i<maxi;i++){
            if(set.find(i)==set.end()){
                ans.push_back(i);
            }
            else{
                continue;
            }
        }
        return ans;
    }
};
