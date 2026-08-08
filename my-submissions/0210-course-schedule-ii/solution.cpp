class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDeg(numCourses,0);
        for(auto &it: prerequisites){
            adj[it[1]].push_back(it[0]);
            inDeg[it[0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(inDeg[i]==0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it: adj[node]){
                inDeg[it]--;
                if(inDeg[it]==0){
                    q.push(it);
                }
            }
        }
        if(topo.size()<numCourses) return {};//if there is a cycle the courses cant be completed so return empty array
        return topo;
    }
};
