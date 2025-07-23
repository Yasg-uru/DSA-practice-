class Solution {
public:
    int m , n ;
    vector<vector<int>>g;
    vector<vector<int>>directions ={{0,1},{0,-1},{1,0},{-1,0}};
    int MOD = 1e9+7;
    vector<vector<int>>memo;
    int solve(int i  , int j){
        if(memo[i][j]!=-1) return memo[i][j];
        int result = 1;// current element makes one sequence 
        for(auto& dir :directions){
            int i_= i+dir[0];
            int j_= j+dir[1];
            if(i_>=0 and i_<m and j_>=0 and j_<n and g[i_][j_]<g[i][j]){
                result=(result%MOD+solve(i_, j_)%MOD)%MOD;
            }
        }
        return memo[i][j]=result%MOD;
    }
    int countPaths(vector<vector<int>>& grid) {
        int result = 0 ;
        g= grid;
        m = grid.size();
        n = grid[0].size();
        memo.resize(m+1, vector<int>(n+1, -1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                result=(result%MOD+solve(i,j)%MOD)%MOD;
            }
        }
        return result ;
    }
};