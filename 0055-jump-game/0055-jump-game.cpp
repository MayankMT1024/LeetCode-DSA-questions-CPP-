class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), maxInd = 0;
        for(int i = 0; i < n && i <= maxInd; i++){
            maxInd = max(maxInd, i + nums[i]);
            if(maxInd >= n - 1) return true;
        }

        return false;
    }
};