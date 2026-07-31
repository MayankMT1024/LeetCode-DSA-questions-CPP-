class Solution {
public:
    int minAddToMakeValid(string s) {
        int openBrackets = 0;
        int additionsRequired = 0;
        
        for (char c : s) {
            if (c == '(') {
                openBrackets++;
            } else if (c == ')') {
                if (openBrackets > 0) {
                    openBrackets--;
                } else {
                    additionsRequired++;
                }
            }
        }
        
        return openBrackets + additionsRequired;
    }
};