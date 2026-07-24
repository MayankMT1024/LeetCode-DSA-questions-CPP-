class Solution {
public:
    int solve(int idx, int prev_idx, vector<int>& nums, vector<vector<int>>& memo) {
        if (idx == nums.size()) {
            return 0;
        }
        
        if (memo[idx][prev_idx + 1] != -1) {
            return memo[idx][prev_idx + 1];
        }
        
        int skip = solve(idx + 1, prev_idx, nums, memo);
        int take = 0;
        
        if (prev_idx == -1 || nums[idx] > nums[prev_idx]) {
            take = 1 + solve(idx + 1, idx, nums, memo);
        }
        
        return memo[idx][prev_idx + 1] = max(skip, take);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(n+1, -1));
        return solve(0, -1, nums, memo);
    }
};