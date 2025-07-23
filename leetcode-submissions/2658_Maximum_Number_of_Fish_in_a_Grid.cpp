class Solution {
public:
    vector<vector<int>>directions ={{0,1},{0,-1},{1,0},{-1,0}};
    int m,n;
    int dfs(int i ,int j,vector<vector<int>>&grid){
        if(i>=m or j>=n or i<0 or j<0 or grid[i][j]==0){
            return 0;
        }
        int Fishes =grid[i][j];
        grid[i][j]=0;
        for(auto dir :directions){
            int i_=i+dir[0];
            int j_=j+dir[1];
            Fishes+=dfs(i_,j_,grid);

        }
        return Fishes;


    }
    
    int findMaxFish(vector<vector<int>>& grid) {
        int maxFishes =INT_MIN;
        m=grid.size();
        n=grid[0].size();

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]>0){
                    maxFishes=max(maxFishes, dfs(i,j,grid));
                }
            }
        }
        return maxFishes;
    }
};