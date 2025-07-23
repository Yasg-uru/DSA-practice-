class Solution {
public:
int dfs(int i,int j,vector<vector<int>>&grid,vector<vector<bool>>&visited,int rows,int cols){
    //base cases
    if(i<0 or j<0 or i>=rows or j>=cols or grid[i][j]==0 or visited[i][j]==true){
        return 0;

    }
    int maxGold=0;
    visited[i][j]=true;
   
    //now trying all the possibilities of the acheiving more gold 
    //creating a 2d direction array 
    vector<vector<int>>dir={{-1,0},{0,-1},{1,0},{0,1}};
    for(int currRow=0;currRow<dir.size();currRow++){

    maxGold=max(maxGold,dfs(i+dir[currRow][0],j+dir[currRow][1],grid,visited,rows,cols));

    }
    visited[i][j]=false;
    return maxGold+grid[i][j];

}
    int getMaximumGold(vector<vector<int>>& grid) {
        //now i am solving this question by using the DFS + Backtracking+prouning 
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<bool>>visited(rows,vector<bool>(cols));
        int maxgold=INT_MIN;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]!=0){

                maxgold=max(maxgold,dfs(i,j,grid,visited,rows,cols));
                }
            }
        }
        return maxgold;

    }
};