class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for(int i = 0; i < asteroids.size(); i++){
            if(ans.empty() || asteroids[i] > 0 || ans.back() < 0) ans.push_back(asteroids[i]);
            else{
                while(!ans.empty() && ans.back() > 0 && -asteroids[i] > ans.back()) ans.pop_back();
                if(ans.empty() || ans.back() < 0) ans.push_back(asteroids[i]);
                if(!ans.empty() && -asteroids[i] == ans.back()) ans.pop_back();
            }
        }
        return ans;
    }
};