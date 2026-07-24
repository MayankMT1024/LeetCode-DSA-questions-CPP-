class Solution {
public:
    int LongestBitonicSequence(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp1(n, 1);  

        int maxLen = 0;

        for(int i = 0; i < n; i++) {
            for(int prev = 0; prev < i; prev++) {
                if(arr[prev] < arr[i] && dp1[i] < dp1[prev] + 1) {
                    dp1[i] = dp1[prev] + 1;
                }
            }
        }
    
        vector<int> dp2(n, 1);  
        
        for(int i = n-1; i >= 0; i--) {
            for(int prev = n-1; prev > i; prev--) {
                if(arr[prev] < arr[i] && dp2[i] < dp2[prev] + 1) {
                    dp2[i] = dp2[prev] + 1; 
                }
            }
            
            if (dp1[i] > 1 && dp2[i] > 1) {
                maxLen = max(maxLen, dp1[i] + dp2[i] - 1);
            }
        }
        
        return maxLen;
    }

    int minimumMountainRemovals(vector<int>& nums) {
        return nums.size() - LongestBitonicSequence(nums);
    }
};