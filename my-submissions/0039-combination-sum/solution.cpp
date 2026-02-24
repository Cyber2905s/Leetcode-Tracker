class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        comb(0,target,candidates,ans,ds);
        return ans;
    }
    void comb(int ind,int target,vector<int>& cand, vector<vector<int>>& ans,vector<int>& ds){
        if(ind == cand.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        if(cand[ind]<=target){
            ds.push_back(cand[ind]);
            comb(ind,target-cand[ind],cand,ans,ds);
            ds.pop_back();
        }
        comb(ind+1,target,cand,ans,ds);
    }
};
