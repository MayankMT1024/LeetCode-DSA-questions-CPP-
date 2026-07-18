class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        int total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }

        vector<vector<int>> left_sums(n + 1);
        vector<vector<int>> right_sums(n + 1);

        int total_masks = 1 << n;
        for (int mask = 0; mask < total_masks; ++mask) {
            int left_sz = 0, left_val = 0;
            int right_sz = 0, right_val = 0;
            
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    left_sz++;
                    left_val += nums[i];
                    
                    right_sz++;
                    right_val += nums[n + i];
                }
            }
            left_sums[left_sz].push_back(left_val);
            right_sums[right_sz].push_back(right_val);
        }

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