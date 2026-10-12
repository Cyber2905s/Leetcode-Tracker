class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n<=1) return 0;
        unordered_map<int,vector<int>> graph;
        for(int i=0;i<n;i++){
            graph[arr[i]].push_back(i);
        }
        vector<bool> vis(n,0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        int steps = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz){
                int curr = q.front();
                q.pop();
                if(curr==n-1){
                    return steps;
                }
                if(graph.count(arr[curr])){
                    for(int next: graph[arr[curr]]){
                        if(!vis[next]){
                            vis[next] = 1;
                            q.push(next);
                        }
                    }
                    graph.erase(arr[curr]);
                }
                if(curr+1<n && !vis[curr+1]){
                    vis[curr+1] = 1;
                    q.push(curr+1);
                }
                if(curr-1>=0 && !vis[curr-1]){
                    vis[curr-1] = 1;
                    q.push(curr-1);
                }
                sz--;
            }
            steps++;
        }
        return -1;
    }
};
