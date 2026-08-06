class Solution {
private:
    bool dfs(int node,vector<vector<int>>& adj,vector<int> &vis,vector<int> &path){
        vis[node]=1;
        path[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,path)) return true;
            }
            else if(path[it]){
                return true;
            }
        }
        path[node]=0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto &pre: prerequisites){
            adj[pre[1]].push_back(pre[0]);
        }
        vector<int> vis(numCourses,0);
        vector<int> path(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,path)){
                    return false;
                }
            }
        }
        return true;
    }
};
