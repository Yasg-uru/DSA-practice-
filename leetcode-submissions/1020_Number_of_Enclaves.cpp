class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
         int m = grid.size(), n = grid[0].size();
        vector<vector<int>>directions = {{0 , 1}, {1, 0 }, {-1, 0}, {0 , -1}};

        queue<pair<int , int >>q;
        for(int i=0;i<m;i++){
            if(grid[i][0]==1){
                q.push({i, 0});
                  grid[i][0]=2;
            }
            if(grid[i][n-1]==1){
                q.push({i, n-1});
                  grid[i][n-1]=2;
            }
        }
        for(int j=0;j<n;j++){
            if(grid[0][j]==1){
                q.push({0 , j});
                  grid[0][j]=2;
            }
            if(grid[m-1][j]==1){
                q.push({m-1,j});
                grid[m-1][j]=2;
            }
        }
        while(not q.empty()){
            int i= q.front().first;
            int j = q.front().second;
            q.pop();
            
            for(auto& dir:directions){
                int i_= dir[0]+i;
                int j_ = dir[1]+j;
                if(i_>=0 and j_>=0 and i_<m and j_<n and grid[i_][j_]==1){
                    q.push({i_, j_});
                     grid[i_][j_]=2;
                }
            }
        }
        int totalEnclaves =0 ;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                   totalEnclaves++;
                }
            }
        }
        return totalEnclaves;
    }
};