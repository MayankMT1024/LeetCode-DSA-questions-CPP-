class Solution {
    int getDigitCount(int n) {
        int count = 0;
        while (n > 0) {
            count++;
            n /= 10;
        }
        return count;
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        string digits = "123456789";
        vector<int> ans;
        
        int lowLen = getDigitCount(low);
        int highLen = getDigitCount(high);
        
        for (int length = lowLen; length <= highLen; ++length) {
            for (int i = 0; i + length <= 9; ++i) {
                int num = stoi(digits.substr(i, length));
                
                if (num >= low && num <= high) {
                    ans.push_back(num);
                }
            }
        }
        
        return ans;
    }
};