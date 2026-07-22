class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<bool> prev(m+1, false), cur(m+1, false);
        prev[0] = true;
        for(int i = 1; i <= m; i++){
            bool flag = true;
            for(int j = 1; j <= i; j++){
                if(p[j-1] != '*'){
                    flag = false;
                    break;
                }
            }
            prev[i] = flag;
        }

        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    cur[j] = prev[j-1];
                } else if (p[j-1] == '*'){
                    cur[j] = prev[j] | cur[j-1];
                } else cur[j] = false;
            }
            prev = cur;
        }

        return prev[m];
    }
};