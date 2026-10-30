class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        if(n==1) return -0;
        vector<vector<pair<int,int>>> adj(n);
        for(auto& it: edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<vector<int>> dist(n,vector<int>(k+1,1e9));
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> pq;
        dist[0][1] = 0;
        pq.push({0, {0, 1}});
        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second.first;
            int cnt = pq.top().second.second;
            pq.pop();
            if (d > dist[u][cnt]) continue;
            if (u == n - 1) return d;
            for (auto& edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;
                int next_cnt = (labels[u] == labels[v]) ? cnt + 1 : 1;
                if (next_cnt <= k && d + w < dist[v][next_cnt]) {
                    dist[v][next_cnt] = d + w;
                    pq.push({dist[v][next_cnt], {v, next_cnt}});
                }
            }
        }
        return -1;
    }
};
