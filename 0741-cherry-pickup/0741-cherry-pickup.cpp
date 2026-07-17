class Solution {
    int memo[50][50][50];
    int N;

    int solve(vector<vector<int>>& grid, int r1, int c1, int r2) {
        int c2 = r1 + c1 - r2;
        
        if (r1 == N || c1 == N || r2 == N || c2 == N || grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            return -1e9;
        }
        
        if (r1 == N - 1 && c1 == N - 1) {
            return grid[r1][c1];
        }
        
        if (memo[r1][c1][r2] != -1) {
            return memo[r1][c1][r2];
        }

        int cherries = grid[r1][c1];
        if (r1 != r2) {
            cherries += grid[r2][c2];
        }

        int max_next = max({
            solve(grid, r1 + 1, c1, r2 + 1),
            solve(grid, r1, c1 + 1, r2 + 1),
            solve(grid, r1 + 1, c1, r2),
            solve(grid, r1, c1 + 1, r2)
        });

        return memo[r1][c1][r2] = cherries + max_next;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        N = grid.size();
        memset(memo, -1, sizeof(memo));
        return max(0, solve(grid, 0, 0, 0));
    }
};