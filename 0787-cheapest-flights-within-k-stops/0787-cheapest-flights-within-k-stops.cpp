class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        queue<pair<int, int>> q;
        q.push({src, 0});
        int stops = 0;

        while (!q.empty() && stops <= k) {
            int size = q.size();
            
            while (size--) {
                auto [node, cost] = q.front();
                q.pop();

                for (auto& [neighbor, price] : adj[node]) {
                    if (cost + price < dist[neighbor]) {
                        dist[neighbor] = cost + price;
                        q.push({neighbor, cost + price});
                    }
                }
            }
            stops++;
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};