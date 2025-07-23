class Solution {
public:
vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>result(m,vector<int>(n,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<>>pq;
        pq.push({0,0,0});
        result[0][0]=0;
        while(not pq.empty()){
            vector<int>curr=pq.top();
            pq.pop();
            int currCost=curr[0];
            int currRow =curr[1];
            int currCol=curr[2];
            for(int i=0;i<directions.size();i++){
                int newRow=currRow+directions[i][0];
                int newCol=currCol+directions[i][1];
                if(newRow>=0 && newRow<m && newCol<n && newCol>=0){
                    int currDirection=grid[currRow][currCol];
                int directionCost=(currDirection-1)!=i?1:0;
                int newCost=directionCost+currCost;
                if(newCost<result[newRow][newCol]){
                    result[newRow][newCol]=newCost;
                    pq.push({newCost,newRow,newCol});
                }
                }
            }
        }
        return result[m-1][n-1];
    }
};