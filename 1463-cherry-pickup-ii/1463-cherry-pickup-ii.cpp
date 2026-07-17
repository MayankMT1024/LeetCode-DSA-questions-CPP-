class Solution {
    int memo[70][70][70];
    int R, C;

    int solve(vector<vector<int>>& grid, int r, int c1, int c2) {
        if (c1 < 0 || c1 >= C || c2 < 0 || c2 >= C) {
            return -1e9;
        }
        
        if (r == R) {
            return 0;
        }
        
        if (memo[r][c1][c2] != -1) {
            return memo[r][c1][c2];
        }

        int cherries = grid[r][c1];
        if (c1 != c2) {
            cherries += grid[r][c2];
        }

        int max_next = -1e9;
        for (int dc1 = -1; dc1 <= 1; ++dc1) {
            for (int dc2 = -1; dc2 <= 1; ++dc2) {
                max_next = max(max_next, solve(grid, r + 1, c1 + dc1, c2 + dc2));
            }
        }

        return memo[r][c1][c2] = cherries + max_next;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        R = grid.size();
        C = grid[0].size();
        memset(memo, -1, sizeof(memo));
        
        return max(0, solve(grid, 0, 0, C - 1));
    }
};