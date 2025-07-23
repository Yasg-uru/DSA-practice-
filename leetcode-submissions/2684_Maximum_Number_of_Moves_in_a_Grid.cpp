class Solution {
public:
    int dfs(int row,int col,vector<vector<int>>&grid){
        int moves=0;
        // we need to create an array of directions 
        // {-1,0,1}
        vector<int>directions={-1,1,0};
        for(int dir:directions){
            int newRow=row+dir;
            int newCol=col+1;
            if(newRow<grid.size() and newCol<grid[0].size() && grid[newRow][newCol]>grid[row][col]){
              moves=max(moves,1+dfs(newRow,newCol,grid));  
            }
        }
        return moves;

    }
    int maxMoves(vector<vector<int>>& grid) {
        int result=0;
        for(int row=0;row<grid.size();row++){
            result=max(result,dfs(row,0,grid));
        }
        return result ;
    }
};