class Solution {
    void generateSums(vector<int>& arr, int index, int count, int current_sum, vector<vector<int>>& sums) {
        if (index == arr.size()) {
            sums[count].push_back(current_sum);
            return;
        }
        
        generateSums(arr, index + 1, count + 1, current_sum + arr[index], sums);
        
        generateSums(arr, index + 1, count, current_sum, sums);
    }

public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        int total_sum = 0;
        
        for (int num : nums) {
            total_sum += num;
        }

        vector<int> left_half;
        vector<int> right_half;
        for (int i = 0; i < n; ++i) {
            left_half.push_back(nums[i]);
            right_half.push_back(nums[n + i]);
        }

        vector<vector<int>> left_sums(n + 1);
        vector<vector<int>> right_sums(n + 1);

        generateSums(left_half, 0, 0, 0, left_sums);
        generateSums(right_half, 0, 0, 0, right_sums);

        for (int i = 0; i <= n; ++i) {
            sort(right_sums[i].begin(), right_sums[i].end());
        }

        int min_diff = 2e9; 
        
        for (int k = 0; k <= n; ++k) {
            for (int left_val : left_sums[k]) {
                int target = total_sum / 2 - left_val;
                int right_k = n - k;
                
                int low = 0;
                int high = right_sums[right_k].size() - 1;
                
                while (low <= high) {
                    int mid = low + (high - low) / 2;
                    int right_val = right_sums[right_k][mid];
                    
                    int current_sum = left_val + right_val;
                    int current_diff = abs(total_sum - 2 * current_sum);
                    
                    if (current_diff < min_diff) {
                        min_diff = current_diff;
                    }
                    
                    if (right_val < target) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
            }
        }

        return min_diff;
    }
};