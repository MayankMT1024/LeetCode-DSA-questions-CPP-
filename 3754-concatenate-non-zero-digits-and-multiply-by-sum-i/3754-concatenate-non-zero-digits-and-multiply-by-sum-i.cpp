class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long sum = 0;
        string s = to_string(n);
        
        for (char ch : s) {
            if (ch > '0' && ch <= '9') {
                int digit = ch - '0';
                x = (x * 10) + digit; 
                sum += digit;         
            }
        }
        
        return x * sum;
    }
};