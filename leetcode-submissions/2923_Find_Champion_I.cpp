class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int maxonesrow=0;
        int maxones=INT_MIN;
        for(int i=0;i<grid.size();i++){
                int count=0;
            for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]==1){
                count++;
            }
            }
            if(count>maxones){
                maxones=count;
                maxonesrow=i;
            }
            
        }
        return maxonesrow;

    }
};