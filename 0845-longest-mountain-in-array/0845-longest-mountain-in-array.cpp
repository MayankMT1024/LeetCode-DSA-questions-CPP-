class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0; // A mountain must have at least 3 elements

        vector<int> dp1(n, 1);  
        int maxLen = 0;

        // Step 1: Check ONLY the immediate left neighbor for a contiguous climb
        for(int i = 1; i < n; i++) {
            if(arr[i] > arr[i - 1]) {
                dp1[i] = dp1[i - 1] + 1;
            }
        }
    
        vector<int> dp2(n, 1);  
        
        // Step 2: Check ONLY the immediate right neighbor for a contiguous descent
        for(int i = n - 2; i >= 0; i--) {
            if(arr[i] > arr[i + 1]) {
                dp2[i] = dp2[i + 1] + 1; 
            }
            
            // Check if it's a valid peak (must have both climb and descent)
            if (dp1[i] > 1 && dp2[i] > 1) {
                maxLen = max(maxLen, dp1[i] + dp2[i] - 1);
            }
        }
        
        return maxLen;
    }
};