class Solution {
    int solve(int i, int j, const vector<int>& cuts, vector<vector<int>>& memo) {
        if (j - i <= 1) {
            return 0;
        }
        
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        
        int min_cost = INT_MAX;
        
        for (int k = i + 1; k < j; ++k) {
            int cost = solve(i, k, cuts, memo) + solve(k, j, cuts, memo) + cuts[j] - cuts[i];
            min_cost = min(min_cost, cost);
        }
        
        return memo[i][j] = min_cost;
    }
    
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        int m = cuts.size();
        vector<vector<int>> memo(m, vector<int>(m, -1));
        
        return solve(0, m - 1, cuts, memo);
    }
};