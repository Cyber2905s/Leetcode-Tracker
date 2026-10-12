class Solution {
private:
    bool dfs(vector<int>& arr, int curr,vector<bool>& vis){
        if(curr<0 || curr>=arr.size() || vis[curr]){
            return false;
        }
        if(arr[curr]==0) return true;
        vis[curr] = 1;
        return dfs(arr,curr+arr[curr],vis)||dfs(arr,curr-arr[curr],vis);
    }
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n,0);
        return dfs(arr,start,vis);
    }
};
