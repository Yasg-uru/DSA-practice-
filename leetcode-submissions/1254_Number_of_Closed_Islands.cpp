class Solution {
public:
    int m , n ;
    void DFS(vector<vector<int>>&grid, int i , int j ){
        if(i<0 or j<0 or j>=n or i>=m or grid[i][j]!=0){
        return ;
        }
        grid[i][j] = 2;
        DFS(grid , i+1, j);
        DFS(grid , i-1, j);
        DFS(grid , i, j-1);
        DFS(grid , i , j+1);
    }
    int closedIsland(vector<vector<int>>& grid) {
        m= grid.size(), n = grid[0].size();
        for(int i=0 ;i<m;i++){
        DFS(grid , i , 0);
        DFS(grid, i , n-1);
        }
        for(int j =0 ;j<n;j++){
            DFS( grid , 0 , j);
            DFS(grid , m-1 ,j);
        }
        int count =0 ;
        for(int i=1;i<m-1;i++){
        for(int j=1;j<n-1;j++){
            if(grid[i][j]==0){
                DFS(grid , i , j);
                count++;
            }
        }
        }
        return count ;
        
    }
};