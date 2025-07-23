class Solution {
public:
    typedef pair<int ,pair<int , int >>P;
    vector<vector<int>>directions = {  {-1, -1}, {1, 0}, {-1, 0}, {-1, 1}, {0, 1}, 
  {1, 1}, {1, 0}, {1, -1}, {0, -1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // now doing this question by using the dijkstra's algorithm as we know the shortest path algorithm 
        priority_queue<P ,vector<P>, greater<P>>pq;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>result(m , vector<int>(n , INT_MAX));
    if (grid[0][0] == 1 || grid[m-1][n-1] == 1) return -1;
        result[0][0]= 1 ;
        // mark the starting point as visited 
        grid[0][0]= 0;
        pq.push({0 , {0 , 0 }});
        while(not pq.empty()){
            int dist= pq.top().first;
            auto coord = pq.top().second ;
            pq.pop();
            int i= coord.first;
            int j = coord.second ;
            if(i==m-1 and j==n-1){
                return dist+1;
            }
            // we need to explore the neighbours
            for(auto& dir : directions){
                int i_ = dir[0]+i ;
                int j_ = dir[1]+j;
                if(i_>=0 and i_<m and j_>=0 and j_<n and grid[i_][j_]==0){
                    // we need to check the compare with the result 
                    if((dist+1)<result[i_][j_]){
                        pq.push({dist+1, {i_, j_}});
                        result[i_][j_]= dist+1;
                        grid[i_][j_]= 1;
                        //marking as visited
                    }
                }
            }
        }
        return (result[m-1][n-1]==INT_MAX)?-1:result[m-1][n-1]+1;
    }
};