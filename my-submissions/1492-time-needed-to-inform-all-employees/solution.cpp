class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if(n==1) return 0;
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            if(manager[i]!=-1){
                adj[manager[i]].push_back(i);
            }
        }
        int time = 0;
        vector<int> vis(n,0);
        vis[headID] = 1;
        queue<pair<int,int>> q;
        q.push({headID,time});
        while(!q.empty()){
            int node = q.front().first;
            int t = q.front().second;
            time = max(time,t);
            q.pop();
            for(int neigh: adj[node]){
                if(!vis[neigh]){
                    vis[neigh] = 1;
                    q.push({neigh,t+informTime[node]});
                }
            }
        }
        return time;
    }
};
