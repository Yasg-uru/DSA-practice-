class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstRowRemainSum=accumulate(begin(grid[0]),end(grid[0]),0LL);
        long long secondRowRemainSum=0;
        long long miniMizedSumRobot2Sum =LONG_LONG_MAX;
        for(int robot1Col=0;robot1Col<grid[0].size();robot1Col++){
            firstRowRemainSum-=grid[0][robot1Col];
            long long bestOfRobot2=max(firstRowRemainSum,secondRowRemainSum);
            miniMizedSumRobot2Sum=min(miniMizedSumRobot2Sum,bestOfRobot2);
            secondRowRemainSum+=grid[1][robot1Col];
        }
        return miniMizedSumRobot2Sum'
    }
};