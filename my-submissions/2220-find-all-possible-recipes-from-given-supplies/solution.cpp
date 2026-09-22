class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,vector<string>> adj;
        unordered_map<string,int> inDeg;
        int n = recipes.size();
        for(int i=0;i<n;i++){
            inDeg[recipes[i]] = ingredients[i].size();
            for(auto it:ingredients[i]){
                adj[it].push_back(recipes[i]);
            }
        }
        queue<string> q;
        for(auto it: supplies){
            q.push(it);
        }
        vector<string> ans;
        unordered_set<string> rSet(recipes.begin(),recipes.end());
        while(!q.empty()){
            string curr = q.front();
            q.pop();
            if(rSet.find(curr)!=rSet.end()){
                ans.push_back(curr);
            }
            for(auto next: adj[curr]){
                inDeg[next]--;
                if(inDeg[next]==0){
                    q.push(next);
                }
            }
        }
        return ans;
    }
};
