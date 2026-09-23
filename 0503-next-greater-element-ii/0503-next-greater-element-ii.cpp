class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int n = nums.size();
        vector<int> ans(n, -1);
        
        for(int i = n - 2; i >= 0; i--){
            while (!s.empty() && nums[i] >= s.top()) s.pop();
            s.push(nums[i]);
        }

        for(int i = n - 1; i >= 0; i--){
            while (!s.empty() && nums[i] >= s.top()) s.pop();
            if(!s.empty()){ans[i] = s.top();}
            s.push(nums[i]);
        }

        return ans;
    }
};