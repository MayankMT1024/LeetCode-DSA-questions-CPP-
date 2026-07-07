class Solution {
public:
    void recursiveCall(int i, string sumPath, long sum, long prev, string num, int target, vector<string>& ans){
        if(i == num.size()){
            if(sum == target)
            {
                ans.push_back(sumPath);
            }
            return;
        }

        for (int j = i; j < num.size(); j++){
            if(j > i && num[i] == '0') break;

            long number = stol(num.substr(i, j-i+1));
            string tempPath = num.substr(i, j-i+1);

            if(i == 0)
            {
                recursiveCall(j + 1, tempPath, number, number, num, target, ans);
            } else{
                recursiveCall(j + 1, sumPath + '+' + tempPath, sum + number, number, num, target, ans);
                recursiveCall(j + 1, sumPath + '-' + tempPath, sum - number, -number, num, target, ans);
                recursiveCall(j + 1, sumPath + '*' + tempPath, sum - prev + (prev*number), prev *number, num, target, ans);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        recursiveCall(0, "", 0, 0, num, target, ans);
        return ans;
    }
};