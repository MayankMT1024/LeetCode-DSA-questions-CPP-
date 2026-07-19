class Solution {
public:
    string smallestSubsequence(string s) {
        int last_occ[26] = {0};
        bool in_stack[26] = {false};
        
        for (int i = 0; i < s.length(); ++i) {
            last_occ[s[i] - 'a'] = i;
        }
        
        string result = "";
        
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            
            if (in_stack[c - 'a']) {
                continue;
            }
            
            while (result.length() > 0 && result.back() > c && last_occ[result.back() - 'a'] > i) {
                in_stack[result.back() - 'a'] = false;
                result.pop_back();
            }
            
            result += c;
            in_stack[c - 'a'] = true;
        }
        
        return result;
    }
};