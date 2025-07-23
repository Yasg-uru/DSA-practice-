class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>>matrix(rowSum.size(),vector<int>(colSum.size(),0));
        int i=0,j=0;
        int n=rowSum.size(),m=colSum.size();
        while(i<n and j<m){
            int minele=min(rowSum[i],colSum[j]);
            rowSum[i]-=minele;
            colSum[j]-=minele;
            matrix[i][j]=minele;
            if(rowSum[i]==0){
                i++;
            }else if(colSum[j]==0){
                j++;
            }else{
                i++;
                j++;
            }

        }
        return matrix;
    }
};