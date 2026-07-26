class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        int n = series1.size() - 1, m = series2.size() - 1;
        int temp1 = 0, temp2 = 0;
        vector<vector<int>> ans;

        while(n >= 0 && m >= 0){
            int time1 = series1[n][0];
            int time2 = series2[m][0];
            if(time1 == time2){
                int value = series1[n][1] + series2[m][1];
                ans.push_back({time1, value});
                temp1 = series1[n][1];
                temp2 = series2[m][1];
                n--;
                m--;
            } else if(time1 > time2){
                int value = series1[n][1] + temp2;
                ans.push_back({time1, value});
                temp1 = series1[n][1];
                n--;
            } else {
                int value = series2[m][1] + temp1;
                ans.push_back({time2, value});
                temp2 = series2[m][1];
                m--;
            }
        }

        while(n >= 0){ 
            ans.push_back({series1[n][0], temp2 + series1[n][1]});
            n--;
        }

        while(m >= 0){ 
            ans.push_back({series2[m][0], temp1 + series2[m][1]});
            m--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};