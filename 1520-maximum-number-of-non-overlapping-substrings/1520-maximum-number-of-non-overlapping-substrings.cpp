class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int first[26], last[26];
        memset(first, -1, sizeof(first));
        memset(last, -1, sizeof(last));
        
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (first[s[i] - 'a'] == -1) {
                first[s[i] - 'a'] = i;
            }
            last[s[i] - 'a'] = i;
        }
        
        bool adj[26][26] = {false};
        bool rev_adj[26][26] = {false};
        
        for (int i = 0; i < 26; i++) {
            if (first[i] != -1) {
                for (int j = first[i]; j <= last[i]; j++) {
                    int v = s[j] - 'a';
                    if (i != v) {
                        adj[i][v] = true;
                        rev_adj[v][i] = true;
                    }
                }
            }
        }

        //kosarajus algorith
        
        bool visited[26] = {false};
        int stack[26];
        int top = 0;

        //step 1 finshing time
        
        auto dfs1 = [&](auto& self, int u) -> void {
            visited[u] = true;
            for (int v = 0; v < 26; v++) {
                if (adj[u][v] && !visited[v]) {
                    self(self, v);
                }
            }
            stack[top++] = u;
        };
        
        for (int i = 0; i < 26; i++) {
            if (first[i] != -1 && !visited[i]) {
                dfs1(dfs1, i);
            }
        }

        //step 2 
        
        memset(visited, false, sizeof(visited));
        int scc_id[26];
        int curr_scc = 0;
        
        auto dfs2 = [&](auto& self, int u) -> void {
            visited[u] = true;
            scc_id[u] = curr_scc;
            for (int v = 0; v < 26; v++) {
                if (rev_adj[u][v] && !visited[v]) {
                    self(self, v);
                }
            }
        };
        
        for (int i = top - 1; i >= 0; i--) {
            int u = stack[i];
            if (!visited[u]) {
                dfs2(dfs2, u);
                curr_scc++;
            }
        }
        
        vector<bool> is_sink(curr_scc, true);
        vector<int> scc_min_L(curr_scc, n + 1);
        vector<int> scc_max_R(curr_scc, -1);
        
        for (int i = 0; i < 26; i++) {
            if (first[i] != -1) {
                int id = scc_id[i];
                scc_min_L[id] = min(scc_min_L[id], first[i]);
                scc_max_R[id] = max(scc_max_R[id], last[i]);
                
                for (int v = 0; v < 26; v++) {
                    if (adj[i][v] && scc_id[i] != scc_id[v]) {
                        is_sink[id] = false;
                    }
                }
            }
        }
        
        vector<string> result;
        for (int i = 0; i < curr_scc; i++) {
            if (is_sink[i]) {
                result.push_back(s.substr(scc_min_L[i], scc_max_R[i] - scc_min_L[i] + 1));
            }
        }
        
        return result;
    }
};