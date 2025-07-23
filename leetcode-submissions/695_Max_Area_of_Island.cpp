class Solution {
public:
    int m , n ;
    vector<vector<int>>directions = {{0 , 1}, {1, 0 }, {0 , -1}, {-1 , 0}};

    int BFS(vector<vector<int>>& grid, int i , int j ){
        queue<pair<int , int >>q;
        q.push({i , j});
        int area =0;

        while(not q.empty()){
            int i= q.front().first ;
            int j  =q.front().second ;
            q.pop();
            for(auto& dir : directions ){
                int i_ = dir[0]+i ;
                int j_ = dir[1]+j ;
                if(i_>=0 and j_>=0 and i_<m and j_<n and grid[i_][j_]==1 ){
                        area++;
                        grid[i_][j_]=0 ;
                        q.push({i_, j_});
                }
            }
        }    
        return area ;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // in this question we need to find the maxInfaction on    any bfs call 
        m = grid.size(),  n = grid[0].size();
        int maxArea = 0 ;
        for(int i=0;i<m;i++){
            for(int j =0 ;j<n;j++){
                if(grid[i][j]==1){
                    maxArea = max(maxArea , BFS(grid , i , j));

                }
            }
        }      
        return maxArea;
    }
};