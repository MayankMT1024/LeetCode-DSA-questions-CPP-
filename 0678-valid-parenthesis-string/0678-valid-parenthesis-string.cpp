class Solution {
public:
    bool checkValidString(string s) {
        int max = 0, min = 0;

        for(char ch: s){
            if(ch == '('){
                min++;
                max++;
            } else if (ch == ')'){
                min--;
                max--;
            } else {
                min--;
                max++;
            }

            if(max < 0) return false;
            if (min < 0) min = 0;
        }

        return (min == 0);
    }
};