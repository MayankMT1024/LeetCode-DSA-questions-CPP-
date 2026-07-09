class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        vector<vector<int>> min_effort(m, vector<int>(n, 1e9));

        pq.push({0, 0, 0});
        min_effort[0][0] = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [effort, r, c] = pq.top();
            pq.pop();

            if (r == m - 1 && c == n - 1) return effort;
            if (effort > min_effort[r][c]) continue;

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int next_effort = max(effort, abs(heights[r][c] - heights[nr][nc]));
                    
                    if (next_effort < min_effort[nr][nc]) {
                        min_effort[nr][nc] = next_effort;
                        pq.push({next_effort, nr, nc});
                    }
                }
            }
        }
        return 0;
    }
};