class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {nums[i], i};
        }
        
        sort(arr.begin(), arr.end());
        
        vector<int> pos(n);
        for (int i = 0; i < n; ++i) {
            pos[arr[i].second] = i;
        }
        
        int LOG = 18;
        vector<vector<int>> st(LOG, vector<int>(n));
        
        int r = 0;
        for (int i = 0; i < n; ++i) {
            while (r < n && arr[r].first - arr[i].first <= maxDiff) {
                r++;
            }
            st[0][i] = r - 1;
        }
        
        for (int j = 1; j < LOG; ++j) {
            for (int i = 0; i < n; ++i) {
                st[j][i] = st[j - 1][st[j - 1][i]];
            }
        }
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (const auto& q : queries) {
            int u = pos[q[0]];
            int v = pos[q[1]];
            
            if (u > v) swap(u, v);
            
            if (u == v) {
                ans.push_back(0);
                continue;
            }
            
            if (st[LOG - 1][u] < v) {
                ans.push_back(-1);
                continue;
            }
            
            int jumps = 0;
            for (int j = LOG - 1; j >= 0; --j) {
                if (st[j][u] < v) {
                    u = st[j][u];
                    jumps += (1 << j);
                }
            }
            
            ans.push_back(jumps + 1);
        }
        
        return ans;
    }
};