class Solution {
public:
    int largestInteger(int n, int s) {
        int ans = 0;

        while(n){
            if(s == 0) return ans;
            if(s > 9){
                ans += 9 * pow(10, n - 1);
                s -= 9;
            } else {
                ans += s * pow(10, n-1);
                s = 0;
            }

            n--;
        }

        if (s == 0) return ans;
        return -1;
    }
};