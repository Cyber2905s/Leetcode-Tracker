class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int n = nums.size();
        vector<int> freq(n+1,-1);
        vector<int> ans;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==x){
                cnt++;
                freq[cnt] = i;
            }
        }
        for(int i=0;i<queries.size();i++){
            if(queries[i]>cnt) ans.push_back(-1);
            else{
                ans.push_back(freq[queries[i]]);
            }
        }
        return ans;
    }
};
