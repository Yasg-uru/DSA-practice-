class Solution {
public:
    int m , n ;
    bool check(vector<vector<int>>& grid, int row , int col){
        for(int i = row+1;i<m;i++){
            if(grid[i][col]!=grid[row][col]){
                return true ;
            }
        }
        for(int j =col+1 ;j<n;j++){
            if(grid[row][j]==grid[row][col]){
                return true ;
            }
        }
        return false;
    }
    bool satisfiesConditions(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        for(int i =0 ;i<m;i++){
            for(int j =0 ;j<n;j++){
                if(check(grid , i , j )){
                    return false;
                }
            }
        }
        return true ;
    }
};