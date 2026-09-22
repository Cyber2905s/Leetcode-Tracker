class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> adjRev(V);
        vector<int> inDeg(V,0);
        //Reverse the adj list
        for(int i=0;i<V;i++){
            for(auto it: graph[i]){
                adjRev[it].push_back(i);
                inDeg[i]++;
            }
        }
        vector<int> safe;
        queue<int> q;
        for(int i=0;i<V;i++){
            if(inDeg[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safe.push_back(node);
            for(auto it: adjRev[node]){
                inDeg[it]--;
                if(inDeg[it]==0){
                    q.push(it);
                }
            }
        }
        sort(safe.begin(),safe.end());
        return safe;
    }
};
