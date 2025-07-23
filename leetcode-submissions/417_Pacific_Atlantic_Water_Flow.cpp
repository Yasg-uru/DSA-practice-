class Solution {
public:

//now we need to define globally that can make simplicity in solving the things
vector<vector<int>>directions={{0,1},{1,0},{0,-1},{-1,0}};
vector<vector<int>>h;
int rows,cols;


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        //now we need to create a two queues one for pacific and second one for atlantic 
        h=heights;
        rows=h.size();
         cols=h[0].size();
        //now we clonned the array into the another array
        queue<pair<int,int>>pacificocean;
        queue<pair<int,int>>atlanticocean;

        // now we are traversing multiple bfs traversal at single time

        //we are inserting the elements according to the question
        for(int i=0;i<rows;i++){
            pacificocean.push({i,0});
            atlanticocean.push({i,cols-1});

        }
        for(int j=0;j<cols;j++){
            pacificocean.push({0,j});
            atlanticocean.push({rows-1,j});
        }
       vector<vector<bool>>p=bfs(pacificocean);
       vector<vector<bool>>a=bfs(atlanticocean);

      vector<vector<int>>result;
       for(int i=0;i<rows;i++){
           for(int j=0;j<cols;j++){
               if(p[i][j] and a[i][j] ){
                   result.push_back({i,j});
               }
           }

       }

return result;
    }
    vector<vector<bool>> bfs(queue<pair<int,int>>&q){
        vector<vector<bool>>visited(rows,vector<bool>(cols,false));
        while(not q.empty()){
            auto cell=q.front();
            q.pop();
            int i=cell.first;
            int j=cell.second;
            visited[i][j]=true;
            for(int d=0;d<4;d++){
                int newRow=i+directions[d][0];
                int newCol=j+directions[d][1];
                if(newRow<0 or newRow>=rows or newCol<0 or newCol>=cols){
                    continue;
                }
                if(visited[newRow][newCol]){
                    continue;
                }
                if(h[i][j]>h[newRow][newCol]){
                    continue;
                }
                q.push({newRow,newCol});
            }

        }
        return visited;
    }
};