class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n+1);
        for(auto& it: paths){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> col(n,0);
        for(int i=1;i<=n;i++){
            vector<bool> used(5,0);
            for(int neigh:adj[i]){
                used[col[neigh-1]] = true;
            }
            for(int j=1;j<=4;j++){
                if(!used[j]){
                    col[i-1] = j;
                    break;
                }
            }
        }
        return col;
    }
};
