class Solution {
public:
vector<vector<int>>arr;
int n,m;
int f(int i,int j){
    

    //base cases
    if(i>=n or j>=m or i<0 or j<0 ){
        return INT_MAX;
    } 
    if(i==n-1 and j==m-1){
        return arr[n-1][m-1];
    }
    return arr[i][j]+min(f(i+1,j),f(i,j+1));
}
    int minPathSum(vector<vector<int>>& grid) {
    arr=grid;
     n=arr.size();
     m=arr[0].size();
    return f(0,0);
    }
};