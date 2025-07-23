class Solution {
public:
    int t[71][71][71];
    int m , n ;
    
    int solve(int row , int col1 , int col2 ,vector<vector<int>>& grid ){
        if(col1<0 or col2<0 or col1>=n or col2>=n){
            return 0;
        }
        if(row==m-1){
            //if we have reached at the last row then we need to check the col is same or not 
            if(col1==col2){
return grid[row][col1];}
            return grid[row][col1]+grid[row][col2];
        }
        if(t[row][col1][col2]!=-1) return t[row][col1][col2];
        int curr = 0 , maxAns =0 ;
        if(col1!=col2){
            curr =(grid[row][col1]+grid[row][col2]);
        }else{
            curr =grid[row][col1];
            
        }
       for(int dir1 = -1;dir1<=1;dir1++){
           for(int dir2=-1;dir2<=1;dir2++ ){
               int newC1 = dir1+col1;
           int newC2 = dir2+col2;
           maxAns = max(maxAns , solve(row+1 , newC1 , newC2 , grid));
           }
       }
        return t[row][col1][col2]=  maxAns+curr ;
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(t,-1 ,sizeof(t));
        m = grid.size(), n = grid[0].size();
        
        return solve(0 , 0 ,n-1  , grid );
    }
};