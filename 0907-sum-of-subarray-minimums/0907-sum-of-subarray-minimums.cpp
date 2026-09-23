class Solution {
public:
    vector<int> findNSE(vector<int> &arr, int n) {
        vector<int> ans(n);
        stack<int> st;
        
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            
            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return ans;
    }
    
    vector<int> findPSEE(vector<int> &arr, int n) {
        vector<int> ans(n);
        stack<int> st;
        
        for(int i=0; i < n; i++) {
            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(), mod = 1e9 + 7;
        int sum = 0;
        vector<int> nse = findNSE(arr, n);
        vector<int> psee = findPSEE(arr, n);

        for(int i = 0; i < n; i++){
            int left = i - psee[i];
            int right = nse[i] - i;
            
            long long totalWays = (left * right) % mod;
            long long contribution = (totalWays * arr[i]) % mod;
            
            sum = (sum + contribution) % mod;
        }

        return sum;
    }
};