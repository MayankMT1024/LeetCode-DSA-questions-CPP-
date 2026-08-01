class Solution {
public:
    int countPalindromes(string s) {
        long long mod = 1e9 + 7;
        int n = s.length();
        if (n < 5) return 0;
        
        vector<long long> left_cnt(10, 0), right_cnt(10, 0);
        vector<vector<long long>> left_pair(10, vector<long long>(10, 0));
        vector<vector<long long>> right_pair(10, vector<long long>(10, 0));
        
        for (int i = n - 1; i >= 0; --i) {
            int c = s[i] - '0';
            for (int d = 0; d < 10; ++d) {
                right_pair[c][d] = (right_pair[c][d] + right_cnt[d]) % mod;
            }
            right_cnt[c]++;
        }
        
        long long ans = 0;
        
        for (int i = 0; i < n; ++i) {
            int c = s[i] - '0';
            
            right_cnt[c]--;
            for (int d = 0; d < 10; ++d) {
                right_pair[c][d] = (right_pair[c][d] - right_cnt[d] + mod) % mod;
            }
            
            for (int d1 = 0; d1 < 10; ++d1) {
                for (int d2 = 0; d2 < 10; ++d2) {
                    ans = (ans + left_pair[d1][d2] * right_pair[d2][d1]) % mod;
                }
            }
            
            for (int d = 0; d < 10; ++d) {
                left_pair[d][c] = (left_pair[d][c] + left_cnt[d]) % mod;
            }
            left_cnt[c]++;
        }
        
        return ans;
    }
};