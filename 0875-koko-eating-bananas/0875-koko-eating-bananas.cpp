class Solution {
public:
    int maxElement(vector<int>& a){
        int maxi = INT_MIN;
        for(int i = 0; i < a.size(); i++){
            maxi = max(maxi, a[i]);
        }
        return maxi;
    }

    long long totalHours(vector<int>&arr, int n){
        long long total = 0;
        for(int i = 0; i < arr.size(); i++)
            total += (arr[i] + n - 1)/n;
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1,high = maxElement(piles);
        while(low<=high){
            int mid = low + (high - low)/2;
            long long total = totalHours(piles, mid);
            if(total <= h)
                high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};