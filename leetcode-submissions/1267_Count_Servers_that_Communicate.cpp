class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<int>IndexColCount(n,0);
        vector<int>IndexRowCount(m,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    IndexColCount[j]++;
                    IndexRowCount[i]++;
                }
            }
        }
        int resultantServers=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 and (IndexRowCount[i]>1 or IndexColCount[j]>1)){
                    resultantServers++;
                }
            }
        }
        return resultantServers;
    }
};