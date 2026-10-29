class Solution {
int timer;
    vector<int> tin, tout;
    vector<vector<int>> up;
    vector<vector<int>> adj;
    vector<int> bit;
    int BIT_SIZE;

    void bit_update(int idx, int val) {
        for (; idx < BIT_SIZE; idx += idx & -idx) {
            bit[idx] ^= val;
        }
    }

    int bit_query(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx) {
            res ^= bit[idx];
        }
        return res;
    }

    void range_update(int l, int r, int val) {
        bit_update(l, val);
        bit_update(r + 1, val);
    }

    void dfs(int u, int p) {
        tin[u] = ++timer;
        up[u][0] = p;
        for (int i = 1; i < 17; ++i) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }

        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u);
            }
        }
        tout[u] = timer;
    }

    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int get_lca(int u, int v) {
        if (is_ancestor(u, v)) return u;
        if (is_ancestor(v, u)) return v;
        for (int i = 16; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v)) {
                u = up[u][i];
            }
        }
        return up[u][0];
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        adj.assign(n, vector<int>());
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        tin.resize(n);
        tout.resize(n);
        up.assign(n, vector<int>(17, 0));
        timer = 0;

        dfs(0, 0);

        BIT_SIZE = n + 2;
        bit.assign(BIT_SIZE, 0);

        // Initialize values in Fenwick tree
        for (int i = 0; i < n; ++i) {
            int char_mask = 1 << (s[i] - 'a');
            range_update(tin[i], tout[i], char_mask);
        }

        vector<bool> ans;
        for (const string& q_str : queries) {
            stringstream ss(q_str);
            string type;
            ss >> type;

            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;
                if (s[u] != c) {
                    int old_mask = 1 << (s[u] - 'a');
                    int new_mask = 1 << (c - 'a');
                    int diff_mask = old_mask ^ new_mask;
                    range_update(tin[u], tout[u], diff_mask);
                    s[u] = c;
                }
            } else if (type == "query") {
                int u, v;
                ss >> u >> v;
                int mask_u = bit_query(tin[u]);
                int mask_v = bit_query(tin[v]);
                int lca = get_lca(u, v);
                int lca_val_mask = 1 << (s[lca] - 'a');

                int path_mask = mask_u ^ mask_v ^ lca_val_mask;

                // At most one bit set to 1
                bool can_be_palindrome = (path_mask == 0) || ((path_mask & (path_mask - 1)) == 0);
                ans.push_back(can_be_palindrome);
            }
        }

        return ans;
    }
};
