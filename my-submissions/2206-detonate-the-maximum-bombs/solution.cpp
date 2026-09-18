class Solution {
private:
    void dfs(int node,int& cnt, int n,vector<int>& vis, vector<vector<int>>& bombs){
        vis[node] = 1;
        cnt++;
        long long x1 = bombs[node][0];
        long long y1 = bombs[node][1];
        long long r1 = bombs[node][2];
        for(int i=0;i<n;i++){
            if(!vis[i]){
                long long dx = bombs[i][0]-x1;
                long long dy = bombs[i][1]-y1;
                if((dx*dx+dy*dy)<=r1*r1){
                    dfs(i,cnt,n,vis,bombs);
                }
            }
        }
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        int ans = -1e9;
        for(int i=0;i<n;i++){
            vector<int> vis(n,0);
            int temp = 0;
            dfs(i,temp,n,vis,bombs);
            ans = max(temp,ans);
        }
        return ans;
    }
};
