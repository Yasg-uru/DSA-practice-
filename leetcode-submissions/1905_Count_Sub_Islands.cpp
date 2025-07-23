class Solution {
public:
    bool isIsland=false;
    void dfs(int i,int j,int n,int m,vector<vector<int>>&grid1,vector<vector<int>>&grid2){
        if(grid1[i][j]!=grid2[i][j]){
            isIsland=false;
        }
        grid1[i][j]=grid2[i][j]=0;
       vector<vector<int>> directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
        for(int k=0;k<4;k++){
            int x=i+directions[k][0];
            int y=j+directions[k][1];
            if(x<n and y<m and x>=0 and y>=0 and grid2[x][y]==1){
                dfs(x,y,n,m,grid1,grid2);
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        // we need to use dfs traversal technique for finding the number of islands

        int count =0;
        int x=grid1.size();
        int y=grid1[0].size();
        for(int i=0;i<grid1.size();i++){
            for(int j=0;j<grid1[0].size();j++){
                if(grid2[i][j]==1){
                    isIsland=true;
                    dfs(i,j,x,y,grid1,grid2);
                    if(isIsland){
                        count++;
                    }
                }
            }
        }
        return count;

    }
};