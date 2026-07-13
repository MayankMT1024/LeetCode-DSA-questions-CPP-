class DisjointSet {
public:
    vector<int> rank, parent, size;
    
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        
        if (ulp_u == ulp_v) return;
        
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } 
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        
        // Since grid values are uniquely 0 to (n^2 - 1), 
        // we can map each time/elevation directly to its row and column.
        vector<pair<int, int>> timeToPos(n * n);
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                timeToPos[grid[r][c]] = {r, c};
            }
        }
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        
        // The water level rises from t = 0 to t = n^2 - 1
        for (int t = 0; t < n * n; t++) {
            int r = timeToPos[t].first;
            int c = timeToPos[t].second;
            int nodeNo = r * n + c;
            
            // Check 4-directional neighbors
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                // If the neighbor is within bounds AND is already underwater (elevation <= t)
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] <= t) {
                    int adjNodeNo = nr * n + nc;
                    ds.unionBySize(nodeNo, adjNodeNo);
                }
            }
            
            // If the start (0, 0) and the destination (n-1, n-1) belong to the same component
            if (ds.findUPar(0) == ds.findUPar(n * n - 1)) {
                return t;
            }
        }
        
        return 0;
    }
};