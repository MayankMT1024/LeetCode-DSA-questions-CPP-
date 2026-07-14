class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> L(26, INT_MAX);
        vector<int> R(26, -1);
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            L[s[i] - 'a'] = min(L[s[i] - 'a'], i);
            R[s[i] - 'a'] = max(R[s[i] - 'a'], i);
        }
        
        vector<string> ans;
        int last_right = -1;
        
        for (int i = 0; i < n; i++) {
            if (i == L[s[i] - 'a']) {
                int right = getValidRightBoundary(s, i, L, R);
                
                if (right != -1) {
                    if (i > last_right) {
                        ans.push_back(""); 
                    }
                    ans.back() = s.substr(i, right - i + 1);
                    last_right = right;
                }
            }
        }
        
        return ans;
    }
    
private:
    int getValidRightBoundary(const string& s, int i, const vector<int>& L, const vector<int>& R) {
        int right = R[s[i] - 'a'];
        
        for (int j = i; j <= right; j++) {
            if (L[s[j] - 'a'] < i) {
                return -1; 
            }
            right = max(right, R[s[j] - 'a']);
        }
        
        return right;
    }
};