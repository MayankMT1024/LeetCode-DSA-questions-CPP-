class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int n = n1 + n2;
        if(n1 <= n2){
            int low = 0, high = n1;
            while(low <= high){
            int mid = (low + high)/2;
            int mid2 = (n + 1)/2 - mid;
            int left1 = (mid == 0) ? INT_MIN : nums1[mid - 1];
            int right1 = (mid == n1) ? INT_MAX : nums1[mid];
            
            int left2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int right2 = (mid2 == n2) ? INT_MAX : nums2[mid2];
            
            if (left1 > right2) {
                high = mid - 1;
            } 
            else if (left2 > right1) {
                low = mid + 1;
            } 
            else {
                if (n % 2 == 1) {
                    return max(left1, left2);
                } else {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                }
            }
        } 
        }else return findMedianSortedArrays(nums2, nums1);
        
        return 0.0;
    }
};