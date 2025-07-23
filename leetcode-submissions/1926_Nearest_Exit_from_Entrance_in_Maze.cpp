class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int , int >>q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]]= '+';
        int steps =  0;
        int m = maze.size();
        int n  = maze[0].size();
        vector<vector<int>>directions  = {{0,1}, {1,0}, {0 , -1}, {-1, 0}};

        while(not q.empty()){
            int size = q.size();
            while(size--){
                pair<int, int> temp= q.front();
                int i = temp.first;
                int j = temp.second ; 
           if(make_pair(entrance[0], entrance[1])!=temp){
             if(i==0 or i==m-1 or j==0 or j==n-1 ){
                return steps ;
            }
           }
                q.pop();
            for(auto& dir : directions ){
                int i_ = i+dir[0];
                int j_ = j+ dir[1];
                if(i_>=0 and i_<m and j_>=0 and j_<n and maze[i_][j_]!='+'){
                    q.push({i_, j_});
                    maze[i_][j_]= '+';

                }
            }
            }
            steps++;

        }
        return -1 ;
    }
};