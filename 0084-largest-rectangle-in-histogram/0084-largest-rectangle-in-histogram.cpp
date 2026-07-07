class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size(), maxA = 0;

        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int ele = st.top();
                st.pop();
                int nge = i;
                int pse = st.empty() ? -1 : st.top();
                maxA = max(maxA, heights[ele] * (nge - pse - 1));
            }
            st.push(i);
        }

        while(!st.empty()){
            int ele = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxA = max(maxA, heights[ele] * (n - pse - 1));
        }

        return maxA;
    }
};