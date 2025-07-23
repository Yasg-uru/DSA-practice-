class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int ans = INT_MAX ;

        for(vector<int>&road : roads){
            ans = min(ans , road[2]);
        }
        return ans ;
    }
};