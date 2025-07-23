class Solution {
public:
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int prevColor =grid[row][col];
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>>q;
        vector<vector<int>>directions = {{0 , 1}, {1, 0}, {0 , -1}, {-1, 0}};
        set<pair<int,int>>visited;
        vector<vector<int>>modified= grid;
        visited.insert({row , col});
        q.push({row , col});
        while(not q.empty()){
            auto [i , j]= q.front();
            q.pop();
            // modified[i][j]=color;
            bool isBorder= false;
            for(auto dir :directions){
                int i_ = dir[0]+i;
                int j_ = dir[1]+j;
                if(i_<0 || i_>=m || j_<0 || j_>=n || grid[i_][j_]!=prevColor ){
                    isBorder = true ;
                }
                else if( !visited.count({i_ , j_}) ){
                    q.push({i_, j_});
                    visited.insert({i_, j_});
                }
            }
            if(isBorder){
                modified[i][j]= color;
            }
        } 
        return modified ;
    }
};