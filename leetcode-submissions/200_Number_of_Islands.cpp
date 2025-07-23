class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cc=0;
        int rows=grid.size();
        int cols=grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='0'){
                    continue;
                }
                //else then c++
                cc++;
              
                queue<pair<int,int>>q;
                q.push({i,j});
                while(not q.empty()){
                    auto currnode=q.front();
                    q.pop();
                    int currRow=currnode.first;
                    int currCol=currnode.second;
                    // now we need to check directionn wise 
                    if(currRow-1>=0 and grid[currRow-1][currCol]=='1'){
                        q.push({currRow-1,currCol});
                        grid[currRow-1][currCol]='0';
                    }
                    if(currCol-1>=0 and grid[currRow][currCol-1]=='1'){
                        q.push({currRow,currCol-1});
                        grid[currRow][currCol-1]='0';

                    }
                    if(currCol+1<cols and grid[currRow][currCol+1]=='1'){
                        q.push({currRow,currCol+1});
                        grid[currRow][currCol+1]='0';
                    }
                    if(currRow+1<rows and grid[currRow+1][currCol]=='1'){
                        q.push({currRow+1,currCol});
                        grid[currRow+1][currCol]='0';
                    }

                }

            }
        }
        return cc;
    }
};