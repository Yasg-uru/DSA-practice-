class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
vector<long long >RowSum(m ), ColSum(n );
        for(int i =0 ;i<m;i++){
            for(int j=0 ;j<n;j++){
                RowSum[i]+=grid[i][j];
                
            }
            
        }
        for(int j =0 ;j<n;j++){
            for(int i =0 ;i<m;i++){
                ColSum[j]+=grid[i][j];
            }
        }
        long long totalSum =0 ;
        for(auto& row : grid){
            for(int val : row){
                totalSum+=val;
            }
        }
        long long  prefixSum =0 ;
        for(int i =0 ;i<m-1;i++){
            prefixSum+=RowSum[i];
            if(prefixSum*2==totalSum){
                return true ;
            }
        }
        prefixSum=0 ;
        for(int j =0 ;j<n-1;j++){
            prefixSum+=ColSum[j];
            if(prefixSum*2==totalSum){
                return true ;
            }
        }
        

return false ;
    }
};