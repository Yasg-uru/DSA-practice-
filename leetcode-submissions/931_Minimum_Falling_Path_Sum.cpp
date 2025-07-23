class Solution {
public:
    int n, m ;
    int t[101][101];
    int  solve(vector<vector<int>>& matrix, int row , int col){
        if(row==m-1) return matrix[row][col];
        int minSum = INT_MAX;
        if(t[row][col]!=-1) return t[row][col];
        // row+1, col-1
        if(row+1<n and col-1>=0){
            minSum = min(minSum, matrix[row][col]+solve(matrix, row+1, col-1));
        }
        // row+1, col
        if(row+1<n){
            minSum= min(minSum, matrix[row][col]+solve(matrix, row+1, col));
        }
        // row+1, col+1
        if(row+1<n and col+1<m){
            minSum = min(minSum , matrix[row][col]+solve(matrix, row+1, col+1));
        }
        return t[row][col]=minSum ;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        memset(t, -1, sizeof(t));
        int row = 0;
        n= matrix.size();
        m=matrix[0].size();
        int minSum = INT_MAX;
        for(int col=0;col<m;col++){
            minSum = min(minSum ,solve(matrix, row , col) );
        }
        return minSum==INT_MAX?0:minSum ;
    }
};