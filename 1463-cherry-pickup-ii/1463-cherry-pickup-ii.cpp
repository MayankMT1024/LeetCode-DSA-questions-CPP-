class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        vector<vector<int>> dp(C, vector<int>(C, 0));

        for (int r = R - 1; r >= 0; --r) {
            vector<vector<int>> curr_dp(C, vector<int>(C, 0));
            
            for (int c1 = 0; c1 < C; ++c1) {
                for (int c2 = 0; c2 < C; ++c2) {
                    int cherries = grid[r][c1];
                    if (c1 != c2) {
                        cherries += grid[r][c2];
                    }

                    if (r == R - 1) {
                        curr_dp[c1][c2] = cherries;
                    } else {
                        int max_next = 0;
                        for (int dc1 = -1; dc1 <= 1; ++dc1) {
                            for (int dc2 = -1; dc2 <= 1; ++dc2) {
                                int nc1 = c1 + dc1;
                                int nc2 = c2 + dc2;
                                
                                if (nc1 >= 0 && nc1 < C && nc2 >= 0 && nc2 < C) {
                                    max_next = max(max_next, dp[nc1][nc2]);
                                }
                            }
                        }
                        curr_dp[c1][c2] = cherries + max_next;
                    }
                }
            }
            dp = curr_dp;
        }

        return dp[0][C - 1];
    }
};