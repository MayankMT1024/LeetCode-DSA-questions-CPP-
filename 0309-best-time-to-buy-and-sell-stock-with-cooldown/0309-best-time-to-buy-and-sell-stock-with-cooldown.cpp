class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        
        int hold = -prices[0];
        int sold = 0;
        int rest = 0;
        
        for (int i = 1; i < prices.size(); ++i) {
            int next_hold = max(hold, rest - prices[i]);
            int next_sold = hold + prices[i];
            int next_rest = max(rest, sold);
            
            hold = next_hold;
            sold = next_sold;
            rest = next_rest;
        }
        
        return max(sold, rest);
    }
};