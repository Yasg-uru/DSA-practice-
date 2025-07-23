class Solution {
public:
    vector<vector<int>>directions ={{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m =isWater.size();
        int n=isWater[0].size();
        vector<vector<int>>heights(m,vector<int>(n,-1));
        queue<pair<int,int>>q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    heights[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(not q.empty()){
           int N =q.size();
           while(N--){
             auto current =q.front();
            q.pop();
            int  i=current.first;
            int j=current.second ;
           for(auto& dir:directions){
            int i_=i+dir[0];
            int j_=j+dir[1];
            if(i_>=0 and i_<m and j_>=0 and j_<n  and  heights[i_][j_]==-1){
                heights[i_][j_]=heights[i][j]+1;
                q.push({i_,j_});
            }
           }
           }
        }
        return heights;
    }
};