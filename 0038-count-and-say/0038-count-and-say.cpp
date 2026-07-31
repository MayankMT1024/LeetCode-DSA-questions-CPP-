class Solution {
public:
    string countAndSay(int n) {
        string current = "1";
        
        for (int i = 1; i < n; ++i) {
            string next = "";
            int count = 1;
            
            for (int j = 1; j < current.length(); ++j) {
                if (current[j] == current[j - 1]) {
                    count++;
                } else {
                    next += to_string(count) + current[j - 1];
                    count = 1;
                }
            }
            
            next += to_string(count) + current.back();
            current = next;
        }
        
        return current;
    }
};