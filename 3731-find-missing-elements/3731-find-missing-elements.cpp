class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> temp;
        int maxi = 0, mini = 0;

        sort(nums.begin(), nums.end());
        int n = nums.size(), it = 0;

        for(int i = nums[0]; i <= nums[n-1]; ++i){
            if (nums[it] == i) it++;
            else{
                temp.push_back(i);
            }
        }

        return temp;
    }
};