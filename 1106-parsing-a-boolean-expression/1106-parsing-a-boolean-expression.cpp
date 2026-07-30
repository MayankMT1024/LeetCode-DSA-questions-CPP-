class Solution {
public:
    bool parseBoolExpr(string expression) {
        vector<char> st;
        
        for (char c : expression) {
            if (c == ',') {
                continue;
            }
            
            if (c == ')') {
                vector<char> curr;
                // Pop all inner boolean values until the '('
                while (st.back() != '(') {
                    curr.push_back(st.back());
                    st.pop_back();
                }
                
                st.pop_back(); // Remove the '('
                char op = st.back(); // Get the operator
                st.pop_back(); // Remove the operator
                
                // Evaluate the expression based on the operator
                if (op == '!') {
                    st.push_back(curr[0] == 't' ? 'f' : 't');
                } else if (op == '&') {
                    bool res = true;
                    for (char val : curr) {
                        if (val == 'f') res = false;
                    }
                    st.push_back(res ? 't' : 'f');
                } else if (op == '|') {
                    bool res = false;
                    for (char val : curr) {
                        if (val == 't') res = true;
                    }
                    st.push_back(res ? 't' : 'f');
                }
            } else {
                // Push operators, '(', 't', and 'f' onto the stack
                st.push_back(c);
            }
        }
        
        // The final result is the only item left in the stack
        return st.back() == 't';
    }
};