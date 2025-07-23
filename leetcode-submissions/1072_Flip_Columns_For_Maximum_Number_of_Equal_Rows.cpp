class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        // we need to find the inverted rows and same row of the current row in the matrix
        int maxCount =INT_MIN;
        int m=matrix.size(),n=matrix[0].size();
        for(auto& currRow:matrix){
            vector<int>inverted(n);
            for(int col=0;col<n;col++){
                inverted[col]=currRow[col]==1?0:1;
            }
            int count =0;
            for(auto& row:matrix){
                if(row==currRow or row==inverted){
                    count++;
                }
            }
            maxCount=max(maxCount,count);

        }
        return maxCount;
    }
};