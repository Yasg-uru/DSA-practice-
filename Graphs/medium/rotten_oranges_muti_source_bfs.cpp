class Solution {
    public:
        int orangesRotting(vector<vector<int>>& grid) {
            queue<pair<int , int >>q;
            int m = grid.size();
            int n = grid[0].size();
            for(int i=0;i<m ;i++){
                for(int j =0;j<n ;j++){
                    if(grid[i][j]==2){
                        q.push({i , j});
    
                    }
                }
            }
            vector<vector<int>>directions = { { 0 , 1} , {0 , -1}, {1, 0 }, {-1 , 0}};
            int minutes =0;
    
            while(not q.empty()){
                int size = q.size();
                while(size--){
                    auto [ i , j ]= q.front();
                    q.pop();
                    for(auto& dir : directions ){
                        int i_ = dir[0]+ i ;
                        int j_ = dir[1]+ j ;
                        if(i_>=0 and j_>=0 and i_<m and j_<n and grid[i_][j_]==1){
                            q.push({i_, j_});
                            grid[i_][j_]= 2;
    
                        }
                    }
                }
                minutes++;// every minutes new level of the oranges will be rotten
            }
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==1){
                        return -1 ;
                    }
                }
            }
            return (minutes>0)?minutes-1:0;
        }
    };