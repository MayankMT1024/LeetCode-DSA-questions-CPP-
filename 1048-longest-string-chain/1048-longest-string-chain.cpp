class Solution {
public:
bool check(string &s1, string &s2){
    if(s1.size()!=s2.size()+1)return false;
    int first=0,sec=0;
    while(first<s1.size()){
        if(s1[first]==s2[sec]){
            first++;sec++;
        }else{
            first++;
        }
    }
    if(first==s1.size() && sec==s2.size()){
        return true;
    }else return false;
}

static bool compareByLength(const std::string &a, const std::string &b) {
    return a.size() < b.size();
}
    int longestStrChain(vector<string>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        sort(nums.begin(),nums.end(),compareByLength);
        int tmp=0;
        int maxi=1;
        for(int ind=0;ind<n;ind++){
            for(int prev=0;prev<ind;prev++){
                if(check(nums[ind],nums[prev])){
                    tmp=dp[ind];
                    dp[ind]=max(dp[ind],1+dp[prev]);
                }maxi=max(maxi,dp[ind]);
            }
        }
        return maxi;
    }
};