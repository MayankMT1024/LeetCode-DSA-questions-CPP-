class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        bool has[2048] = {false};
        for (int x : nums) {
            has[x] = true;
        }
        
        bool pairs[2048] = {false};
        for (int i = 0; i < 2048; ++i) {
            if (!has[i]) continue;
            for (int j = i; j < 2048; ++j) {
                if (has[j]) {
                    pairs[i ^ j] = true;
                }
            }
        }
        
        bool trips[2048] = {false};
        int ans = 0;
        for (int p = 0; p < 2048; ++p) {
            if (!pairs[p]) continue;
            for (int x = 0; x < 2048; ++x) {
                if (has[x] && !trips[p ^ x]) {
                    trips[p ^ x] = true;
                    ans++;
                }
            }
        }
        
        return ans;
    }
};