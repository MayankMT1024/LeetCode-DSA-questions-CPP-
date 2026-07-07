class Solution {
public:
    int trap(vector<int>& height) {
        int leftm = INT_MIN, rightm = INT_MIN, n = height.size();
        int left = 0, right = n-1, total = 0;

        while(left < right){
            if(height[left] <= height[right]){
                if(height[left] < leftm) total += (leftm - height[left]);
                else leftm = height[left];
                left++;
            }
            else{
                if(height[right] < rightm) total += (rightm - height[right]);
                else rightm = height[right];
                right--;
            }
        }

        return total;
    }
};