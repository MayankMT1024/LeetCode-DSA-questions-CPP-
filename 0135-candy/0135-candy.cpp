class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum = 1, i = 1, n = ratings.size();
        while(i < n){
            while(i < n && ratings[i] == ratings[i-1]){
                sum++;
                i++;
            }

            int peak = 1;

            while(i < n && ratings[i] > ratings[i-1]){
                peak++;
                sum += peak;
                i++;
            }

            int down = 1;

            while(i < n && ratings[i] < ratings[i-1]){
                sum+=down;
                down++;
                i++;
            }

            if(down > peak) sum+=(down - peak);
        }

        return sum;
    }
};