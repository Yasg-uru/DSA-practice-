class Solution {
public:
    vector<vector<int>>directions ={{0,1},{0,-1},{1,0},{-1,0}};
    int n ;

    int dfs(int i,int j, vector<vector<int>>&grid,vector<vector<bool>>&visited,int id){
        // base case 
        if(i<0 or j<0 or j>=n or i>=n or grid[i][j]==0  or visited[i][j]){
            return 0  ;
        }
        int size =1;//intially we have size one 
        grid[i][j]=id;
        visited[i][j]=true;
        for(auto& dir:directions){
            int i_=dir[0]+i;
            int j_=dir[1]+j;
            size+=dfs(i_,j_,grid,visited,id);
        }
        return size;
    }

    int largestIsland(vector<vector<int>>& grid) {
        
         n =grid.size();
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        unordered_map<int,int>mp;//this map is responsible for storing the size of the uniqueIds 

        int uniqueIds =2;// assining initial id to 2 because in the grid already exist 0,1 
        int maxArea=0 ;
        for(int i=0;i<n;i++ ){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 and !visited[i][j]){
                    int size =dfs(i,j,grid,visited,uniqueIds);
                    maxArea=max(maxArea,size);
                    mp[uniqueIds]=size;
                    uniqueIds++;

                }
            }
        }
        //after calculating the regions areas we need to check by mutating the one 
        for(int i=0;i<n;i++){
            for(int j =0;j<n ;j++){
                //we need to check the zero value grid 
                if(grid[i][j]==0 ){
                    unordered_set<int>vals;
                    for(auto& dir :directions){
                        int i_=dir[0]+i;
                        int j_=dir[1]+j;
                        if(  i_<n and j_<n and i_>=0 and j_>=0 and grid[i_][j_]!=0){
                            vals.insert(grid[i_][j_]);
                        }
                    }
                    int overallResult =1;// one is because we are converting zero to one 
                    for(auto val : vals){
                        overallResult+=mp[val];
                    }
                    maxArea=max(maxArea, overallResult);

                }
            }
        }

    return maxArea==0? (n*n) : maxArea; 
    }
};