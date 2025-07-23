class Solution {
public:
    int m , n ;
    int bfs(int dx , int dy , int tx , int ty, vector<vector<int>>&forest){
        if (dx == tx && dy == ty) return 0;
        vector<vector<bool>>visited(m , vector<bool>(n , false));
        queue<tuple< int ,int, int >>q;
        q.push({dx , dy, 0 });
        visited[dx][dy]= true ;
        vector<vector<int>>directions = {{0 , 1}, { 1, 0 }, {0 ,-1}, {-1 , 0 }};
        
        while(not q.empty()){
            auto [ i , j , d]= q.front();
            q.pop();
            for(auto& dir : directions ){
                int i_ = i +dir[0];
                int j_ = j + dir[1];
                if(i_<m and j_<n and i_>=0 and j_>=0 and visited[i_][j_]==false and forest[i_][j_]!=0){
                    if(i_==tx and j_==ty){
return d+1; }
                    visited[i_][j_]=true ;
                    q.push({i_, j_, d+1});
                    
                }
            }
            
        }
        return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        vector<vector<int>>trees;
         m = forest.size(), n = forest[0].size();
        for(int i =0 ;i<m;i++){
            for(int j = 0 ;j<n;j++){
               if(forest[i][j]>1) trees.push_back({forest[i][j], i , j});
            }
        }
        sort(trees.begin(), trees.end());
        int dx = 0 , dy =0 , ans=0 ;
        for(auto tree : trees){
            int tx = tree[1], ty = tree[2];
            
             int d  = bfs(dx , dy ,tx , ty, forest );
            if(d==-1){
                return -1;
            }
            ans+=d;
            dx = tx;
            dy = ty;
        }
       
        return ans ;
    }
};