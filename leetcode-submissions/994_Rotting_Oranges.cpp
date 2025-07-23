class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>>q;
        //it represents (i,j),time 
        int m,n;
        m=grid.size();
        n=grid[0].size();
        vector<vector<bool>>visited(m,vector<int>(n,false));
        int maxtime=INT_MIN;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j]=true;
                }
            }
        }
        while(not q.empty()){
            auto node=q.front();
            q.pop();
            maxtime=max(maxtime,node.second);
            int prevtime=node.second;
            int i=q.first.first;
            int j=q.first.second;
            //now we extracted the coordinates of this point then after it we need to 
            if(i>0 and not visited[i-1][j] and grid[i-1][j]==2){
                q.push({{i-1,j},prevtime+1});
                visited[i-1][j]=true;
            }
             if(i>0 and not visited[i-1][j] and grid[i-1][j]==2){
                q.push({{i-1,j},prevtime+1});
                visited[i-1][j]=true;
            }
        }
    }
};