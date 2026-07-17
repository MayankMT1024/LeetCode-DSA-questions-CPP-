class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = 0;
        for (int x : nums) {
            mx = max(mx, x);
        }
        
        // Step 1: Count the frequency of each number
        vector<long long> count(mx + 1, 0);
        for (int x : nums) {
            count[x]++;
        }
        
        // Step 2 & 3: Calculate exact GCD counts using Inclusion-Exclusion
        vector<long long> gcd_exact(mx + 1, 0);
        for (int i = mx; i >= 1; i--) {
            long long multiples = 0;
            // Count how many numbers are multiples of 'i'
            for (int j = i; j <= mx; j += i) {
                multiples += count[j];
            }
            
            // Maximum pairs we can form using these multiples
            long long pairs = multiples * (multiples - 1) / 2;
            
            // Subtract pairs that have a GCD of 2i, 3i, 4i...
            // to leave only the pairs with an exact GCD of 'i'
            for (int j = 2 * i; j <= mx; j += i) {
                pairs -= gcd_exact[j];
            }
            gcd_exact[i] = pairs;
        }
        
        // Step 4: Build a prefix sum array
        vector<long long> prefix(mx + 1, 0);
        for (int i = 1; i <= mx; i++) {
            prefix[i] = prefix[i - 1] + gcd_exact[i];
        }
        
        // Step 5: Answer the queries using Binary Search
        vector<int> ans;
        for (long long q : queries) {
            int pos = upper_bound(prefix.begin(), prefix.end(), q) - prefix.begin();
            ans.push_back(pos);
        }
        
        return ans;
    }
};