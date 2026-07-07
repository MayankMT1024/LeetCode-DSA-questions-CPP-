class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revAdj(n);
        vector<int> indegree(n, 0);
        
        // Reverse the graph and calculate in-degrees for the reversed graph
        for (int i = 0; i < n; i++) {
            for (int next : graph[i]) {
                revAdj[next].push_back(i);
                indegree[i]++; // Original out-degree becomes in-degree
            }
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<bool> isSafe(n, false);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            isSafe[curr] = true;
            
            for (int next : revAdj[curr]) {
                if (--indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        vector<int> safeNodes;
        for (int i = 0; i < n; i++) {
            if (isSafe[i]) {
                safeNodes.push_back(i);
            }
        }
        
        return safeNodes;
    }
};