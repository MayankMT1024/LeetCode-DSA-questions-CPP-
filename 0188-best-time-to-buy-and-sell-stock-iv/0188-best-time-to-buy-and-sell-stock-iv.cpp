class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> next(2, vector<int>(k + 1, 0)), cur(2, vector<int>(k + 1, 0));

        for(int ind = n-1; ind >= 0; --ind){
            for(int buy = 0; buy <= 1; ++buy){
                for(int cap = 1; cap <= k; ++cap){
                    if(buy == 1){
                        cur[buy][cap] = max(next[0][cap] - prices[ind], next[1][cap]);
                    } else {
                        cur[buy][cap] = max(next[1][cap-1] + prices[ind], next[0][cap]);
                    }
                }
            }
            next = cur;
        }

        return next[1][k];
    }
};