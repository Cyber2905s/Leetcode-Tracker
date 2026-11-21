class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        
        // Build original tree adjacency list
        vector<vector<int>> orig_adj(n);
        for (int i = 1; i < n; i++) {
            orig_adj[parent[i]].push_back(i);
        }
        
        vector<int> new_parent = parent;
        vector<int> last_seen(26, -1); // Tracks deepest ancestor for each character 'a'-'z'
        
        // Pass 1: DFS on original tree to determine new parents simultaneously
        auto dfs_reparent = [&](auto& self, int u) -> void {
            int c = s[u] - 'a';
            int prev_ancestor = last_seen[c];
            
            // Update parent if an ancestor with the same character exists
            if (prev_ancestor != -1) {
                new_parent[u] = prev_ancestor;
            }
            
            // Mark current node u as the closest ancestor for character c
            last_seen[c] = u;
            
            for (int v : orig_adj[u]) {
                self(self, v);
            }
            
            // Backtrack when leaving u's subtree
            last_seen[c] = prev_ancestor;
        };
        
        dfs_reparent(dfs_reparent, 0);
        
        // Build the new tree using new_parent
        vector<vector<int>> final_adj(n);
        for (int i = 1; i < n; i++) {
            final_adj[new_parent[i]].push_back(i);
        }
        
        // Pass 2: DFS on final tree to compute subtree sizes
        vector<int> answer(n, 0);
        auto dfs_size = [&](auto& self, int u) -> int {
            int sz = 1;
            for (int v : final_adj[u]) {
                sz += self(self, v);
            }
            return answer[u] = sz;
        };
        
        dfs_size(dfs_size, 0);
        
        return answer;
    }
};
