class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }
        
        if (total_sum < abs(target) || (total_sum + target) % 2 != 0) {
            return 0;
        }
        
        int subset_sum = (total_sum + target) / 2;
        
        vector<int> dp(subset_sum + 1, 0);
        dp[0] = 1;
        
        for (int num : nums) {
            for (int i = subset_sum; i >= num; --i) {
                dp[i] = dp[i] + dp[i - num];
            }
        }
        
        return dp[subset_sum];
    }
};