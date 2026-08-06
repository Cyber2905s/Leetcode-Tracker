class Solution {
private:
    bool dfs(int node,vector<vector<int>>& adj,vector<int> &vis,vector<int> &path,vector<int> &check){
        vis[node]=1;
        path[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,path,check)) {
                    return true;
                }
            }
            else if(path[it]){
                return true;
            }
        }
        check[node]=1;
        path[node]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);
        vector<int> path(n,0);
        vector<int> check(n,0);
        vector<int> safe;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,graph,vis,path,check);
            }
        }
        for(int i=0;i<n;i++){
            if(check[i]){
                safe.push_back(i);
            }
        }
        return safe;
    }
};
