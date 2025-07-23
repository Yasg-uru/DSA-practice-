class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        vector<vector<int>>directions = {{0, 1}, {1, 0 }, {0 , -1}, {-1, 0}};
        queue<vector<int>>q;
        q.push({0 ,  0,health });
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>visited(m , vector<int>(n , -1));
        visited[0][0] = health;

        while(not q.empty()){
            vector<int>vec = q.front();
            int i = vec[0];
            int j = vec[1];
            int currHealth = vec[2];
            if(i==m-1 and j==n-1 and currHealth>=1){
                return true;
            }
            q.pop();
            for(auto& dir : directions ){
                 int i_  = dir[0]+i ;
                 int j_ = dir[1]+j;
                if(i_>=0 and j_>=0 and i_<m and j_<n ){
                    int newHealth  = currHealth-(grid[i_][j_]==1);
                    if(newHealth>0 and visited[i_][j_]<newHealth){
                        q.push({i_, j_ , newHealth});
                    visited[i_][j_] = newHealth ;
                    }
                }
            }
        }
        return false ;
    }
};