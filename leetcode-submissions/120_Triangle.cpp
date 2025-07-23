class Solution {
public:
vector<vector<int>>dp;
vector<vector<int>>arr;
int f(int row ,int col){
 //base case 
 if(row ==arr.size()-1 ){
     return arr[row][col];
      }
      if(dp[row][col]!=-1) return dp[row][col];
      return dp[row][col]=arr[row][col]+min(f(row+1,col),f(row+1,col+1));
}
    int minimumTotal(vector<vector<int>>& triangle) {
        arr=triangle;
        dp.clear();
        dp.resize(205,vector<int>(205,-1));
        return f(0,0);
    }
};