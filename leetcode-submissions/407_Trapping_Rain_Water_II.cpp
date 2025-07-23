class Solution {
public:
    vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
    typedef pair<int,pair<int,int>> pp;

    int trapRainWater(vector<vector<int>>& heightMap) {
    priority_queue<pp,vector<pp>,greater<>>boundary_cells;
    int m=heightMap.size();
    int n=heightMap[0].size();
    vector<vector<bool>>visited(m,vector<bool>(n,false));
    // insert left and right columns 
    for(int row =0;row<m;row++){
        for(int col:{0,n-1}){
            boundary_cells.push({heightMap[row][col],{row,col}});
            visited[row][col]=true;
        }
    }    
    //insert top and bottom row 
    for(int col=0;col<n;col++){
        for(int row :{0,m-1}){
            boundary_cells.push({heightMap[row][col],{row,col}});
            visited[row][col]=true;
        }
    }
    int water=0;

    while(not boundary_cells.empty()){
        pp p=boundary_cells.top();
        boundary_cells.pop();
        int currentHeight=p.first;
        int i=p.second.first;
        int  j=p.second.second;
       for(vector<int>&dir:directions){
        int i_=i+dir[0];
        int j_=j+dir[1];
        if(i_>=0 && i_<m && j_>=0 && j_<n && !visited[i_][j_]){
            water+=max(currentHeight-heightMap[i_][j_],0);
            boundary_cells.push({max(currentHeight,heightMap[i_][j_]),{i_,j_}});
            visited[i_][j_]=true;

        }
       }
    }
    return water;

    }
};