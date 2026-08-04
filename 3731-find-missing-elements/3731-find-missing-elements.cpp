class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }

        vector<int> temp;
        unordered_set<int> st(nums.begin(), nums.end());
        int maxi = nums[0], mini = nums[0];

        for (auto num : nums){
            maxi = max(maxi, num);
            mini = min(mini, num);
        }

        for(int i = mini; i <= maxi; ++i){
            if(st.find(i) == st.end()) temp.push_back(i);
        }

        return temp;
    }
};