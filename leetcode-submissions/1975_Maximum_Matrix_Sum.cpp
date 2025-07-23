class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        // we need to count the negative numbers 
        int negativeCount =0;

        int sum=0;
       
        int minNum=INT_MAX;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]<0){
                    negativeCount++;
                }
                minNum=min(minNum,abs(matrix[i][j]));
                sum+=abs(matrix[i][j]);
            }
        }
       
       if(negativeCount%2==1){
        
        return sum-2*minNum;
       }
       return sum;
    }
};