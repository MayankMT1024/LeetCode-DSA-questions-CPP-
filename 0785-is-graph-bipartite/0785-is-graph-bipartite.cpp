class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        // Initialize color array with -1 (uncolored). 
        // 0 and 1 will represent our two colors.
        vector<int> color(n, -1);
        
        // Check every node to handle disconnected graphs
        for (int i = 0; i < n; ++i) {
            if (color[i] == -1) {
                // If the DFS finds a conflict, return false immediately
                if (!dfs(graph, i, 0, color)) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
private:
    bool dfs(const vector<vector<int>>& graph, int node, int c, vector<int>& color) {
        color[node] = c;
        
        for (int neighbor : graph[node]) {
            // If the neighbor has the exact same color, it's not bipartite
            if (color[neighbor] == c) {
                return false;
            }
            // If the neighbor is unvisited, recursively visit it with the opposite color (1 - c)
            if (color[neighbor] == -1 && !dfs(graph, neighbor, 1 - c, color)) {
                return false;
            }
        }
        
        return true;
    }
};