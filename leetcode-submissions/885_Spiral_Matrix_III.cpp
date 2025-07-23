class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>>directions={
            {0,1},{1,0},{0,-1},{-1,0}
        };
        int steps=1;
        int n=rows*cols;
        vector<vector<int>>ans(n,vector<int>(2));
        ans[0][0]=0;
        ans[1][1]=1;
        int count=1;
        int index=0;
        while(count<n){
            for(int times=0;times<2;times++){
                int dr=directions[index%4][0];
                int dc=directions[index%4][1];
                for(int i=0;i<steps;i++){
                    rStart+=dr;
                    cStart+=dc;
                    if(rStart>=0 and cStart>=0 and cStart<cols and rStart<rows){
                        ans[count][0]=rStart;
                        ans[count][1]=cStart;
                        count++;
                    }

                }
                index++;
            }
            steps++;

        }
        return ans;
        
    }
};