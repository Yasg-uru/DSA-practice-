class Solution {
public:
    vector<vector<int>>directions = {{0 , 1}, {1, 0 }, {0 , -1}, {-1 , 0}};
    int m , n ;
    void dfs(vector<vector<int>>&grid , int i , int j, long long &currSum ){
        if(i<0 or j<0 or j>=n or i>=m or grid[i][j]==0){
            return ;
        }
         currSum+=grid[i][j];
        grid[i][j]= 0 ;
        for(auto& dir : directions){
            dfs(grid , i+dir[0] , j+dir[1], currSum);
        }
        // return currSum ;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size(), n = grid[0].size();
        int count =0;
        for(int i =0 ;i<m;i++){
            for(int j =0 ;j<n;j++){
                    long long currSum = 0 ;
                if(grid[i][j]>=1 ){
                    dfs(grid , i , j, currSum);
                    if(currSum%k==0) count++;
                }
            }
        }
        return count ;
    }
};