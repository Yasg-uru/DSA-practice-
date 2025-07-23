class Solution {
public:
    void modify(vector<vector<int>>&ans , int m , int n , int i ,  bool isRow){
        if(isRow){
            for(int j =0 ;j<n;j++ ){
                ans[i][j]+=1;
            }
        }else {
            for(int row = 0 ;row<m;row++){
                ans[row][i]+=1;
            }
        }
    }
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>>ans(m , vector<int>(n));
        for(auto& I : indices){
            int row = I[0];
            int col = I[1];
            modify(ans, m , n, row, true );
            modify(ans , m , n , col, false);
        }
       int count =0 ;
       for(int i =0 ;i<m;i++){
        for(int j=0 ;j<n;j++){
            if(ans[i][j]%2==1){
                count++;
            }
        }
       }
       return count ;
    }
};