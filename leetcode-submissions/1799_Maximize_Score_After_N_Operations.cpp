class Solution {
public:
    int n ;

    int solve(vector<int>&nums  , vector<bool>visited, int operation, unordered_map<vector<bool>, int>&dp){
        if(dp.count(visited)) return dp[visited];
        int maxAns = 0 ;
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            for(int j=i+1;j<n;j++){
                if(visited[j]) continue;
                visited[i]= true;
                visited[j]= true;
                int currScore = operation*__gcd(nums[i], nums[j]);
                int remainScore = solve(nums , visited, operation+1, dp);
                maxAns = max(maxAns, currScore+remainScore);
                visited[i]= false;
                visited[j]= false;
            }
        }
        return dp[visited]=maxAns ;
        
    }
    int maxScore(vector<int>& nums) {
        n= nums.size();
        vector<bool>visited(n,false);
        int operation = 1;
        unordered_map<vector<bool>, int >dp;
        return solve(nums, visited, operation, dp);
    }
};