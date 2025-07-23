class Solution {
public:
    #define p pair<int,pair<int,int>>
    int minimumTime(vector<vector<int>>& grid) {
        if(grid[0][1]>1  and grid[1][0]>1){
            return -1;
        }
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>result(m,vector<int>(n,INT_MAX));
        result[0][0]=0;
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,{0,0}});
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        vector<vector<int>>directions ={{0,1},{1,0},{0,-1},{-1,0}};
        while(not pq.empty()){
         auto current =pq.top();
         pq.pop();
         int time =current.first;
         int i=current.second.first;
         int j=current.second.second ;
         if(visited[i][j]){
            continue;
         }
         if(i==m-1 and j==n-1){
            return result[m-1][n-1];
         }
         visited[i][j]=true;
         for(auto &dir:directions){
            int newRow=i+dir[0];
            int newCol=j+dir[1];
            if(newRow>=0 and newCol>=0 and newCol<n and newRow<m){
                if(grid[newRow][newCol]<=time){
                    pq.push({time+1,{newRow,newCol}});
                    result[newRow][newCol]=time+1;
                }else if((grid[newRow][newCol]-time)%2==0){
                    pq.push({grid[newRow][newCol]+1,{newRow,newCol}});
                    result[newRow][newCol]=grid[newRow][newCol]+1;
                }else{
                    pq.push({grid[newRow][newCol],{newRow,newCol}});
                    result[newRow][newCol]=grid[newRow][newCol];
                }
            }
         }
        }

        return result[m-1][n-1];


    }
};