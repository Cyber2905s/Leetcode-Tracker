class Solution {
    static const int MOD = 1e9 + 7;
    
    struct Node {
        long long sum = 0;
        long long sq_sum = 0;
        long long lazy = 0;
    };
    
    vector<Node> tree;

    void apply(int node, int l, int r, long long val) {
        val %= MOD;
        long long len = r - l + 1;
        tree[node].sq_sum = (tree[node].sq_sum + 2 * val % MOD * tree[node].sum % MOD + val * val % MOD * len % MOD) % MOD;
        tree[node].sum = (tree[node].sum + val * len % MOD) % MOD;
        tree[node].lazy = (tree[node].lazy + val) % MOD;
    }

    void push(int node, int l, int r) {
        if (tree[node].lazy != 0) {
            int mid = l + (r - l) / 2;
            apply(2 * node, l, mid, tree[node].lazy);
            apply(2 * node + 1, mid + 1, r, tree[node].lazy);
            tree[node].lazy = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr, long long val) {
        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }
        push(node, l, r);
        int mid = l + (r - l) / 2;
        if (ql <= mid) update(2 * node, l, mid, ql, qr, val);
        if (qr > mid) update(2 * node + 1, mid + 1, r, ql, qr, val);
        tree[node].sum = (tree[2 * node].sum + tree[2 * node + 1].sum) % MOD;
        tree[node].sq_sum = (tree[2 * node].sq_sum + tree[2 * node + 1].sq_sum) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        tree.assign(4 * n, Node());
        unordered_map<int, int> last_pos;
        long long totalAns = 0;
        
        for (int j = 0; j < n; j++) {
            int prev = last_pos.count(nums[j]) ? last_pos[nums[j]] : -1;
            int L = prev + 1;
            int R = j;
            update(1, 0, n - 1, L, R, 1);
            totalAns = (totalAns + tree[1].sq_sum) % MOD;
            last_pos[nums[j]] = j;
        }
        
        return totalAns;
    }
};
