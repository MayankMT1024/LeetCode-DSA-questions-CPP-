class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<int> dp(m, 0);
        dp[0] = triangle[0][0];

        for(int i = 1; i < m; i++){
            vector<int> temp(m, 0);
            for(int j = 0; j <= i; j++){
                int top = INT_MAX, top2 = INT_MAX;
                if(i > j) top = dp[j];
                if(j > 0) top2 = dp[j-1];

                temp[j] = triangle[i][j] + min(top, top2);
            }
            dp = temp;
        }

        int mini = dp[0];
        for(int i = 1; i < m; i++){
            mini = min(mini, dp[i]);
        }

        return mini;
    }
};