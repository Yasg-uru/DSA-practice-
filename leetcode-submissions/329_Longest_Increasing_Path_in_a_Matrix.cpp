class Solution {
public:
    int m , n  ;
    vector<vector<int>>directions = { {0 , 1}, {1, 0 }, { 0 , -1 }, { -1 , 0 }};
    
    int solve(vector<vector<int>>&matrix , int i , int j, int prevPicked){
        if(i>=m or j>=n or i<0 or j<0  or matrix[i][j]==-1 or  (prevPicked!=-1 and prevPicked<=matrix[i][j])){
            return 0 ;
            
        }
        int temp = matrix[i][j];
        matrix[i][j] = -1;
        int maxAns =0 ;
        for(auto& dir : directions){
            int i_ = dir[0]+i;
            int j_ = dir[1]+j;
            maxAns = max(maxAns , solve(matrix , i_ , j_ ,temp)+1);
            
        }
        matrix[i][j] = temp;
        return maxAns ;
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        int maxAns = 0 ;
        for(int i =0 ;i<m;i++){
        for(int j =0 ;j<n;j++){
            maxAns = max(maxAns , solve(matrix , i , j, -1 ));
            
        }
        }
        return maxAns ;
    }
};