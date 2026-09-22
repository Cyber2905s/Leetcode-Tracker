#include <vector>

using namespace std;

struct Node {
    int total_prod;
    int count[5];

    Node() {
        total_prod = 1;
        for (int i = 0; i < 5; i++) {
            count[i] = 0;
        }
    }
};

class Solution {
private:
    vector<Node> tree;

    Node mergeNodes(const Node& left, const Node& right, int k) {
        Node res;
        res.total_prod = (left.total_prod * right.total_prod) % k;

        for (int i = 0; i < k; i++) {
            res.count[i] = left.count[i];
        }

        for (int i = 0; i < k; i++) {
            int rem = (left.total_prod * i) % k;
            res.count[rem] += right.count[i];
        }

        return res;
    }

    void build(int node, int l, int r, const vector<int>& nums, int k) {
        if (l == r) {
            int rem = nums[l] % k;
            tree[node].total_prod = rem;
            tree[node].count[rem] = 1;
            return;
        }

        int mid = l + (r - l) / 2;
        build(2 * node, l, mid, nums, k);
        build(2 * node + 1, mid + 1, r, nums, k);
        tree[node] = mergeNodes(tree[2 * node], tree[2 * node + 1], k);
    }

    void update(int node, int l, int r, int idx, int val, int k) {
        if (l == r) {
            for (int i = 0; i < 5; i++) {
                tree[node].count[i] = 0;
            }
            int rem = val % k;
            tree[node].total_prod = rem;
            tree[node].count[rem] = 1;
            return;
        }

        int mid = l + (r - l) / 2;
        if (idx <= mid) {
            update(2 * node, l, mid, idx, val, k);
        } else {
            update(2 * node + 1, mid + 1, r, idx, val, k);
        }

        tree[node] = mergeNodes(tree[2 * node], tree[2 * node + 1], k);
    }

    Node query(int node, int l, int r, int ql, int qr, int k) {
        if (ql <= l && r <= qr) {
            return tree[node];
        }

        int mid = l + (r - l) / 2;
        if (qr <= mid) {
            return query(2 * node, l, mid, ql, qr, k);
        }
        if (ql > mid) {
            return query(2 * node + 1, mid + 1, r, ql, qr, k);
        }

        Node leftRes = query(2 * node, l, mid, ql, qr, k);
        Node rightRes = query(2 * node + 1, mid + 1, r, ql, qr, k);
        return mergeNodes(leftRes, rightRes, k);
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        tree.assign(4 * n, Node());

        build(1, 0, n - 1, nums, k);

        vector<int> result;
        result.reserve(queries.size());

        for (const auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            update(1, 0, n - 1, index, value, k);

            Node resNode = query(1, 0, n - 1, start, n - 1, k);

            result.push_back(resNode.count[x]);
        }

        return result;
    }
};
