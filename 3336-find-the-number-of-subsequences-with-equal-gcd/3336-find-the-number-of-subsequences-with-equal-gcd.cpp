class Solution {
    int memo[201][201][201];
    int MOD = 1e9 + 7;

    int solve(int i, int gcd1, int gcd2, const vector<int>& nums) {
        if (i == nums.size()) {
            if (gcd1 > 0 && gcd1 == gcd2) {
                return 1;
            }
            return 0;
        }

        if (memo[i][gcd1][gcd2] != -1) {
            return memo[i][gcd1][gcd2];
        }

        long long ways = 0;

        ways = (ways + solve(i + 1, gcd1, gcd2, nums)) % MOD;

        int nextGcd1 = (gcd1 == 0) ? nums[i] : gcd(gcd1, nums[i]);
        ways = (ways + solve(i + 1, nextGcd1, gcd2, nums)) % MOD;

        int nextGcd2 = (gcd2 == 0) ? nums[i] : gcd(gcd2, nums[i]);
        ways = (ways + solve(i + 1, gcd1, nextGcd2, nums)) % MOD;

        return memo[i][gcd1][gcd2] = ways;
    }

public:
    int subsequencePairCount(vector<int>& nums) {
        memset(memo, -1, sizeof(memo));
        return solve(0, 0, 0, nums);
    }
};