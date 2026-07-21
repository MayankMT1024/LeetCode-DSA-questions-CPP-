class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string t = "1" + s + "1";
        int n = t.length();
        int orig_ones = 0;
        
        for (char c : s) {
            if (c == '1') orig_ones++;
        }

        vector<pair<char, int>> blocks;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && t[j] == t[i]) {
                j++;
            }
            blocks.push_back({t[i], j - i});
            i = j;
        }

        int max_gain = 0;
        
        for (int k = 1; k < (int)blocks.size() - 1; ++k) {
            if (blocks[k].first == '1' && blocks[k - 1].first == '0' && blocks[k + 1].first == '0') {
                int left_zeros = blocks[k - 1].second;
                int right_zeros = blocks[k + 1].second;
                
                int gain = left_zeros + right_zeros;
                max_gain = max(max_gain, gain);
            }
        }

        return orig_ones + max_gain;
    }
};