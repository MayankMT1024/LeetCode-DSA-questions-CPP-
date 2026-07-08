class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        long long MOD = 1e9 + 7;
        long long INV10 = 700000005; // Modular inverse of 10 under modulo 10^9 + 7
        
        vector<long long> pow10(n + 1, 1), invPow10(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
            invPow10[i] = (invPow10[i - 1] * INV10) % MOD;
        }
        
        vector<int> C(n + 1, 0);
        vector<long long> S(n + 1, 0), P(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            int val = s[i] - '0';
            C[i + 1] = C[i];
            S[i + 1] = S[i];
            P[i + 1] = P[i];
            
            if (val > 0) {
                C[i + 1]++;
                S[i + 1] += val;
                P[i + 1] = (P[i] + val * invPow10[C[i + 1]]) % MOD;
            }
        }
        
        vector<int> ans;
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            long long sum = S[r + 1] - S[l];
            
            if (sum == 0) {
                ans.push_back(0);
                continue;
            }
            
            long long p_diff = (P[r + 1] - P[l] + MOD) % MOD;
            long long x = (p_diff * pow10[C[r + 1]]) % MOD;
            
            ans.push_back((x * (sum % MOD)) % MOD);
        }
        
        return ans;
    }
};