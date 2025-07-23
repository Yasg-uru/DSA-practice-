class Solution {
public:
    int m , n ,nonObstacleCount;
    vector<vector<int>>directions = {{0,1},{0,-1},{1, 0},{-1,0}};
    int solve(int i , int j , vector<vector<int>>& g, int currNonObstacleCnt){
    if(i<0 or j<0 or i>=m or j>=n or g[i][j]==-1)
    }
    int uniquePathsIII(vector<vector<int>>& g) {
        m= g.size();
        n = g[0].size();
        int ans = 0 ;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(g[i][j]==0){
                 nonObstacleCount++;   
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(g[i][j]==1){
                    ans = solve(i , j, g, 0);
                }
            }
        }
        return ans ;
    }
};