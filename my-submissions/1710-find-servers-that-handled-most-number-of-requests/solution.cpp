class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        // Pool of available server IDs: maintained in sorted order
        set<int> available;
        for (int i = 0; i < k; ++i) {
            available.insert(i);
        }
        // Min-heap to track busy servers: {free_time, server_id}
        using BusyServer = pair<long long, int>;
        priority_queue<BusyServer, vector<BusyServer>, greater<BusyServer>> busy;
        vector<int> count(k, 0);
        int n = arrival.size();
        for (int i = 0; i < n; ++i) {
            long long cur_time = arrival[i];
            // Free up all servers that have finished by cur_time
            while (!busy.empty() && busy.top().first <= cur_time) {
                available.insert(busy.top().second);
                busy.pop();
            }
            // If no servers are available, drop the request
            if (available.empty()) {
                continue;
            }
            // Find the first available server with index >= (i % k)
            int target = i % k;
            auto it = available.lower_bound(target);
            // If not found, wrap around to the first available server from index 0
            if (it == available.end()) {
                it = available.begin();
            }
            int server_id = *it;
            count[server_id]++;
            available.erase(it);
            busy.push({cur_time + load[i], server_id});
        }
        // Find the maximum number of requests handled by any server
        int max_requests = *max_element(count.begin(), count.end());
        // Collect all servers that handled max_requests
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            if (count[i] == max_requests) {
                result.push_back(i);
            }
        }
        return result;
    }
};
