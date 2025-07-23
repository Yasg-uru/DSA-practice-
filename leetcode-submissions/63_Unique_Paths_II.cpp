class Solution {
public:
vector<vector<int>>grid;

int f(int i,int j){
    //now setting base cases
    int n=grid.size();
    int m=grid[0].size();
    if(i>=n or j>=m or i<0 or j<0){
        return 0;
    }
    if(i==n-1 and j==m-1){
        return 1;
    }
    if(grid[i][j]==1){
        return 0;
    }
    return f(i,j+1)+f(i+1,j);

    
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        grid=obstacleGrid;
        return f(0,0);
    }
};