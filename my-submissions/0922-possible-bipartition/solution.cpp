class Solution {
private:
    bool dfs(int node,int color, vector<vector<int>>& adj, vector<int>& col){
        col[node] = color;
        for(int neigh: adj[node]){
            if(col[neigh] == color){
                return false;
            }
            if(col[neigh]==0){
                if(!dfs(neigh,-color,adj,col)){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(auto it: dislikes){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> col(n+1,0);
        for(int i=1;i<=n;i++){
            if(col[i]==0){
                if(!dfs(i,1,adj,col)){
                    return false;   
                }
            }
        }
        return true;
    }
};
