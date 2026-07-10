class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, long long>>> adj(n);
        for (const auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        int MOD = 1e9 + 7;

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (const auto& edge : adj[u]) {
                int v = edge.first;
                long long w = edge.second;

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                } 
                else if (dist[u] + w == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};