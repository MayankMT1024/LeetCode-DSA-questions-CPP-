class Solution {
public:
    int minimumPushes(string word) {
        // 1. Count frequencies of each letter
        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }
        
        // 2. Sort frequencies in descending order
        sort(freq.rbegin(), freq.rend());
        
        int total_pushes = 0;
        
        // 3. Assign buttons greedily
        for (int i = 0; i < 26; ++i) {
            if (freq[i] == 0) break; // We've processed all unique characters
            
            // The cost increases by 1 for every 8 characters we process
            int cost = (i / 8) + 1;
            total_pushes += freq[i] * cost;
        }
        
        return total_pushes;
    }
};