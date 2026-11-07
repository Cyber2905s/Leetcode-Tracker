class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        // Min-heap for free servers: {weight, index}
        using FreeServer = pair<int, int>;
        priority_queue<FreeServer, vector<FreeServer>, greater<FreeServer>> free_servers;

        for (int i = 0; i < n; ++i) {
            free_servers.push({servers[i], i});
        }

        // Min-heap for busy servers: {free_time, weight, index}
        using BusyServer = tuple<long long, int, int>;
        priority_queue<BusyServer, vector<BusyServer>, greater<BusyServer>> busy_servers;

        vector<int> ans(m);
        long long curr_time = 0;

        for (int j = 0; j < m; ++j) {
            // Ensure time is at least the arrival time of task j
            curr_time = max(curr_time, (long long)j);

            // If no servers are available, jump time to when the earliest server finishes
            if (free_servers.empty()) {
                curr_time = get<0>(busy_servers.top());
            }

            // Release all servers that finished their tasks by curr_time
            while (!busy_servers.empty() && get<0>(busy_servers.top()) <= curr_time) {
                auto [time, weight, idx] = busy_servers.top();
                busy_servers.pop();
                free_servers.push({weight, idx});
            }

            // Assign task j to the best available free server
            auto [weight, idx] = free_servers.top();
            free_servers.pop();

            ans[j] = idx;
            busy_servers.push({curr_time + tasks[j], weight, idx});
        }

        return ans;
    }
};
