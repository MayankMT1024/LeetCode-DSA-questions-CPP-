class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0, n = prices.size();
        if(n < 2) return 0;
        for(int i = 0; i < n; ++i){
            if(prices[i] < prices[i+1]) sum += (prices[i+1] - prices[i]);
        }
        return sum;
    }
};