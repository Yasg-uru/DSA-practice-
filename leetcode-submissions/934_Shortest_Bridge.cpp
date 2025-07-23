class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int , int>>q;
         vector<vector<int>>directions = {{0 , 1}, {1, 0}, {0 , -1}, {-1, 0}};
        for(int i =0 ;i<n;i++){
            bool isFound = false;
            for(int j =0 ;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i, j});
                    grid[i][j]= -1;
                    isFound = true ;
                }
            }
            if(isFound){
                break;
            }
        }
        while(not q.empty()){
            auto [ i, j]= q.front();
            q.pop();
            for(auto dir : directions){
                int i_ = dir[0]+i;
                int j_ = dir[1]+j;
                if(i_>=0 and j_>=0 and i_<n and j_<n and grid[i_][j_]==1){
                    q.push({i_, j_});
                    grid[i_][j_]= -1;
                }
            }
        }
        queue<tuple<int , int , int >>qu2;
        vector<vector<bool>>visited(n, vector<bool>(n , false));
        for(int i =0 ;i<n;i++){
            for(int j =0 ;j<n;j++){
                if(grid[i][j]==-1){
                    qu2.push({i, j , 0});
                    visited[i][j]= true ;
                }
            }
        }
        while(not qu2.empty()){
            auto [i, j, currDepth]= qu2.front();
            qu2.pop();
            if(grid[i][j]==1){
                return currDepth-1;
            }
            for(auto dir : directions){
                int i_ =dir[0]+i;
                int j_ = dir[1]+j;
                if(i_ >= 0 && i_ < n && j_ >= 0 && j_ < n && visited[i_][j_] == false)
{
                    qu2.push({i_, j_, currDepth+1});
                    visited[i_][j_]= true ;
                }
            }
        }
        return -1;
    }
};