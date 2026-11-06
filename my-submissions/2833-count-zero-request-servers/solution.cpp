class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        // 1. Sort logs by timestamp: log = [server_id, time]
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        // 2. Store queries alongside their original indices and sort by time
        int q_size = queries.size();
        vector<pair<int, int>> sorted_queries(q_size);
        for (int i = 0; i < q_size; ++i) {
            sorted_queries[i] = {queries[i], i};
        }
        sort(sorted_queries.begin(), sorted_queries.end());

        // 3. Two pointers to maintain requests inside [q - x, q]
        // server_count[id] tracks how many requests server 'id' received in current window
        vector<int> server_count(n + 1, 0);
        int active_servers = 0;
        int left = 0, right = 0;
        int log_count = logs.size();

        vector<int> ans(q_size);

        for (const auto& [q_time, original_idx] : sorted_queries) {
            int window_start = q_time - x;
            int window_end = q_time;

            // Expand right boundary: add all requests that occurred <= window_end
            while (right < log_count && logs[right][1] <= window_end) {
                int s_id = logs[right][0];
                if (server_count[s_id] == 0) {
                    active_servers++;
                }
                server_count[s_id]++;
                right++;
            }

            // Shrink left boundary: remove all requests that occurred < window_start
            while (left < log_count && logs[left][1] < window_start) {
                int s_id =logs[left][0];
                server_count[s_id]--;
                if (server_count[s_id] == 0) {
                    active_servers--;
                }
                left++;
            }

            // Idle servers = total servers - active servers
            ans[original_idx] = n - active_servers;
        }

        return ans;
    }
};
