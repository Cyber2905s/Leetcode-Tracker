class Solution {
private:
    bool dfs(int node,int color,vector<vector<int>>& graph,vector<int> &col){
        col[node] = color;
        for(int adj: graph[node]){
                if(col[adj]==-1){
                    if(dfs(adj,!color,graph,col)==false) return false;
                }
                else if(col[adj]==color){
                    return false;
                }
            }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(dfs(i,0,graph,col)==false){
                    return false;
                }
            }
        }
        return true;
    }
};
