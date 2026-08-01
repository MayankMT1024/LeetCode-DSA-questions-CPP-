class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string text = "";
        while (text.length() < b.length()) {
            text += a;
        }
        text += a;
        
        int n = text.length();
        int m = b.length();
        
        long long pHash = 0;
        long long tHash = 0;
        long long base = 31;
        long long mod = 1e9 + 7;
        long long h = 1;
        
        for (int i = 0; i < m - 1; ++i) {
            h = (h * base) % mod;
        }
        
        for (int i = 0; i < m; ++i) {
            pHash = (pHash * base + (b[i] - 'a' + 1)) % mod;
            tHash = (tHash * base + (text[i] - 'a' + 1)) % mod;
        }
        
        for (int i = 0; i <= n - m; ++i) {
            if (pHash == tHash) {
                bool match = true;
                for (int j = 0; j < m; ++j) {
                    if (text[i + j] != b[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    return (i + m - 1) / a.length() + 1;
                }
            }
            
            if (i < n - m) {
                tHash = (tHash - ((text[i] - 'a' + 1) * h) % mod + mod) % mod;
                tHash = (tHash * base + (text[i + m] - 'a' + 1)) % mod;
            }
        }
        
        return -1;
    }
};