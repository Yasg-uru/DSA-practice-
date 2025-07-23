class Solution {
public:
    int n ;
    unordered_map<int, unordered_map<int, bool >>dp;
    int solve(unordered_map<int , int >&mp, vector<int>&stones , int  curr_stone_index , int prevJump){
        if(curr_stone_index==n-1) return true ;
        if(dp.count(curr_stone_index) && dp[curr_stone_index].count(prevJump)){
            return dp[curr_stone_index][prevJump];
        }
        bool res= false ;
        for(int nextJump= prevJump-1;nextJump<=prevJump+1;nextJump++){
            if(nextJump>0){
                // we cant able to move from zero again 
                // currstone + -> nextJump = newCurrStone
                int next_stone = stones[curr_stone_index]+nextJump;
                if(mp.find(next_stone)!=mp.end()){
                    // next stone is valid then we can move there 
                    res= res || solve(mp, stones , mp[next_stone], nextJump);
                }
            }

        }
        return dp[curr_stone_index][prevJump]= res;
    }
    bool canCross(vector<int>& stones) {
        n = stones.size();
        unordered_map<int , int >mp; // stone -> index 
        for(int i=0;i<n;i++){
            mp[stones[i]]= i ;
        }
        dp.clear();

        return solve(mp, stones , 0 , 0 );

    }
};