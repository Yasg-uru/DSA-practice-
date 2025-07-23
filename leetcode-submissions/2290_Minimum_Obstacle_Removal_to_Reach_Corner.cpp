class Solution {
public:
    #define p pair<int,pair<int,int>>
    
    int minimumObstacles(vector<vector<int>>& grid) {
        // now we can implement this question by using the simple shorted path algorithm of the graph 
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>direction={{1,0},{-1,0},{0,1},{0,-1}};
        vector<vector<int>>result(m,vector<int>(n,INT_MAX));
        result[0][0]=0;

        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,{0,0}});
        while(not pq.empty()){
            auto currNode=pq.top();
            pq.pop();
            int i=currNode.second.first;
            int j=currNode.second.second ;
            int currWeight=currNode.first;
            for(auto &dir:direction){
                int newRow=i+dir[0];
                int newCol=j+dir[1];
                if(newRow<m and newCol<n and newRow>=0 and newCol>=0){
                    int wt=grid[newRow][newCol]==1?1:0;

                    if(currWeight+wt<result[newRow][newCol]){
                        result[newRow][newCol]=currWeight+wt;
                    pq.push({currWeight+wt,{newRow,newCol}});

                    }

                }
            }
        }    
        return result[m-1][n-1];

    }
};