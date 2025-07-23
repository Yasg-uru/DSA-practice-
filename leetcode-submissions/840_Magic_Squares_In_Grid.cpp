class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        //now we are implementing the solution by using the brute force approach 
        int cnt=0;
        for(int i=0;i+2<grid.size();i++){
            for(int j=0;j+2<grid[0].size();j++){
              
                    vector<int>rowSum;
                    vector<int>colSum(3,0);
                    for(int r=i;r<i+3;r++){
                        int sum=0;
                        for(int c=j;c<j+3;c++){
                            sum+=grid[r][c];
                            colSum[c-j]+=grid[r][c];
                        }
                        rowSum.push_back(sum);
                    }
                  
                    bool flag=true;
                    for(int i=0;i<3;i++){
                        if(rowSum[i]!=15  ){
                            flag=false;
                            break;
                        }
                        if(colSum[i]!=15){
                            flag=false;
                        }
                    }
                    int diagonalSum1=grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
                     int diagonalSum2=grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j];
                    if(diagonalSum1!=15){
                        flag=false;
                    }
                    if(diagonalSum2!=15){
                        flag=false;
                    }
                    if(flag){
                        cnt++;
                    }
               
            }
        }
        return cnt;
    }
};