class Solution {
public:
    int getlarge(vector<vector<int>>grid,int i,int j){
        int maxele=INT_MIN;
                    for(int row=i;row<i+3;row++){
                        for(int col=j;col<j+3;col++){
                            maxele=max(maxele,grid[row][col]);

                        }
                    }
                    return maxele;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        //now solving this question by the using the nested loop approach that can able to solve this question acurately
        int n=grid.size();
        vector<vector<int>>ans(n-2,vector<int>(n-2));
        //now i am traversing by using the nested loop approach 
        for(int i=0;i<n-2;i++){
            for(int j=0;j<n-2;j++){
               
                    
                  ans[i][j]=getlarge(grid,i,j);
                
            }
        }
return ans;
    }
};