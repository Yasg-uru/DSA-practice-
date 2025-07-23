class Solution {
public:
int totalways(int i,int j,int m,int n){
    //base case
    if(i>=m or j>=n){
        return 0;
    }
    if(i==m-1 and j==n-1){
        return 1;
    }
    return (totalways(i+1,j,m,n)+totalways(i,j+1,m,n));
}
    int uniquePaths(int m, int n) {
      return totalways(0,0,m,n);  
    }
};