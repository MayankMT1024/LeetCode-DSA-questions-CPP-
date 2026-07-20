class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount + 1, 0), cur(amount + 1, 0);
        for(int t = 1; t <= amount; ++t){
            if(t % coins[0] == 0) prev[t] = t / coins[0];
            else prev[t] = 1e9;
        }

        for(int ind = 1; ind < n; ++ind){
            for(int target = 0; target <= amount; ++target){
                int notTake = 0 + prev[target];
                int take = 1e9;
                if(coins[ind] <= target){
                    take = 1 + cur[target - coins[ind]];
                }

                cur[target] = min(take, notTake);
            }

            prev = cur;
        }

        return prev[amount]>= 1e9? -1 : prev[amount];
    }
};