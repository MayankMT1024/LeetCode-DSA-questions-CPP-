class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i = 0; i <= n; i++) dp[i][0] = i;
        for(int j = 0; j <= m; j++) dp[0][j] = j;

        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else{
                    int a = dp[i][j-1];
                    int b = dp[i-1][j];
                    int c = dp[i-1][j-1];

                    dp[i][j] = 1 + min(a, min(b, c));
                }
            }
        }

        return dp[n][m];
    }
};