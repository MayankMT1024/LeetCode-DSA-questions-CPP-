class Solution {
    int getDigitProduct(int num) {
        int product = 1;
        while (num > 0) {
            product *= num % 10;
            num /= 10;
        }
        return product;
    }
    
public:
    int smallestNumber(int n, int t) {
        while (getDigitProduct(n) % t != 0) {
            n++;
        }
        return n;
    }
};