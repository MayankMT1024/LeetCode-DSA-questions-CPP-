class Solution {
public:
    int maxProduct(int n) {
        int largest = 0;
        int second_largest = 0;
        
        while (n > 0) {
            int digit = n % 10;
            
            if (digit >= largest) {
                second_largest = largest;
                largest = digit;
            } else if (digit > second_largest) {
                second_largest = digit;
            }
            
            n /= 10;
        }
        
        return largest * second_largest;
    }
};