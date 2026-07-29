class Solution {
    const int MAX_K = 1000005;

    long long nCk(int n, int k) {
        if (k < 0 || k > n) return 0;
        if (k == 0 || k == n) return 1;
        k = min(k, n - k);
        long long res = 1;
        for (int i = 1; i <= k; ++i) {
            res = res * (n - i + 1) / i;
            if (res >= MAX_K) return MAX_K;
        }
        return res;
    }

    long long countArrangements(vector<int>& count) {
        int total = 0;
        for (int f : count) total += f;
        long long res = 1;
        for (int f : count) {
            if (f > 0) {
                res *= nCk(total, f);
                if (res >= MAX_K) return MAX_K;
                total -= f;
            }
        }
        return res;
    }

public:
    string smallestPalindrome(string s, int k) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        
        vector<int> halfCount(26, 0);
        string midLetter = "";
        
        for (int i = 0; i < 26; ++i) {
            halfCount[i] = count[i] / 2;
            if (count[i] % 2 != 0) {
                midLetter += (char)(i + 'a');
            }
        }
        
        long long totalPerm = countArrangements(halfCount);
        if (k > totalPerm) return "";
        
        string leftHalf = "";
        int halfLen = s.length() / 2;
        
        for (int step = 0; step < halfLen; ++step) {
            for (int i = 0; i < 26; ++i) {
                if (halfCount[i] == 0) continue;
                
                halfCount[i]--;
                long long arrangements = countArrangements(halfCount);
                
                if (arrangements >= k) {
                    leftHalf += (char)(i + 'a');
                    break;
                } else {
                    k -= arrangements;
                    halfCount[i]++;
                }
            }
        }
        
        string rightHalf = leftHalf;
        reverse(rightHalf.begin(), rightHalf.end());
        return leftHalf + midLetter + rightHalf;
    }
};