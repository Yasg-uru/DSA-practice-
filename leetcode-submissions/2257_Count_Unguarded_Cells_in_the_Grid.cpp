class Solution {
public:
       void fillRow(vector<vector<int>>&grid,int row,int col){
        // we need to fill the row forward as well as backward
//for backward we need to start from the column and decreamenting 
        for(int i=col-1;i>=0;i--){
           if(grid[row][i]==-1 or grid[row][i]==1){
            break;
           }
           grid[row][i]=-2;
        }
        for(int i=col+1;i<grid[0].size();i++){
            if(grid[row][i]==-1 or grid[row][i]==1){
                break;
            }
            grid[row][i]=-2;
        }
       }
       void fillCol(vector<vector<int>>&grid,int row ,int col){
        // forward 
        for(int i=row-1;i>=0;i--){
            if(grid[i][col]==-1 or grid[i][col]==1){
                break;
            }
            grid[i][col]=-2;
        }
        for(int i=row+1;i<grid.size();i++){
             if(grid[i][col]==-1  or grid[i][col]==1){
                break;
            }
            grid[i][col]=-2;
        }
       }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // we need to create a array of size  m * n
        vector<vector<int>>grid(m,vector<int>(n,0));
        // we need to place all the guards at their specific coordinates  and walls also 
        for(int i=0;i<guards.size();i++){
            grid[guards[i][0]][guards[i][1]]=1;// representing guard by 1 
        }
        for(int i=0;i<walls.size();i++){
            grid[walls[i][0]][walls[i][1]]=-1;
            //representing walls by -1 

        }
        //after that we need to call the function solve and after that we need to count the number of cells that contains 0 then our final answer is ready 
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                //  if  we found the guard then we need to block all the raws as well as col
                if (grid[i][j]==1){
                    // found a guard
                    fillRow(grid,i,j);
                    fillCol(grid,i,j);

                }
            }
        }
        int count =0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    count ++;
                }
            }
        }
return count ;
        
    }
};