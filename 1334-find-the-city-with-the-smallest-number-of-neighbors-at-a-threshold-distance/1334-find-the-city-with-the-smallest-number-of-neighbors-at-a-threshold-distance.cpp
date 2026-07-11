class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e4 + 1));
        
        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }
        
        for (const auto& edge : edges) {
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];
        }
        
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if(dist[i][k] == 1e4 + 1 || dist[k][j] == 1e4 + 1) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        
        int bestCity = -1;
        int minNeighbors = n;
        
        for (int i = 0; i < n; ++i) {
            int reachable = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    reachable++;
                }
            }
            
            if (reachable <= minNeighbors) {
                minNeighbors = reachable;
                bestCity = i;
            }
        }
        
        return bestCity;
    }
};