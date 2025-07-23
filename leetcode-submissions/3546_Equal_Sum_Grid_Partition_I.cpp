class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int>rowSum(m ), colSum(n );
        for(int i =0 ;i<m;i++){
            for(int j=0 ;j<m;j++){
                rowSum[i]+=grid[i][j];
                
            }
            
        }
        for(int j =0 ;j<n;j++){
            for(int i =0 ;i<m;i++){
                colSum[j]+=grid[i][j];
            }
        }
        int totalSum =0 ;
        for(auto& row : grid){
            for(int val : row){
                totalSum+=val;
            }
        }
        int prefixSum =0 ;
        for(int i =0 ;i<m-1;i++){
            prefixSum+=rowSum[i];
            if(prefixSum*2==totalSum){
                return true ;
            }
        }
        prefixSum=0 ;
        for(int j =0 ;j<n-1;j++){
            prefixSum+=colSum[j];
            if(prefixSum*2==totalSum){
                return true ;
            }
        }
        

return false ;
        
    }
};