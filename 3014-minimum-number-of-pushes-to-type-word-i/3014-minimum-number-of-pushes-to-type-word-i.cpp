class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int total_pushes = 0;

        for(int i = 0; i < n; i++){
            total_pushes += (i / 8) + 1;
        }

        return total_pushes;
    }
};