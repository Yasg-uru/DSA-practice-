class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>>directions = {{0 , 1}, {1, 0 }, {-1, 0}, {0 , -1}};

        queue<pair<int , int >>q;
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                q.push({i, 0});
                  board[i][0]='S';
            }
            if(board[i][n-1]=='O'){
                q.push({i, n-1});
                  board[i][n-1]='S';
            }
        }
        for(int j=0;j<n;j++){
            if(board[0][j]=='O'){
                q.push({0 , j});
                  board[0][j]='S';
            }
            if(board[m-1][j]=='O'){
                q.push({m-1,j});
                board[m-1][j]='S';
            }
        }
        while(not q.empty()){
            int i= q.front().first;
            int j = q.front().second;
            q.pop();
            
            for(auto& dir:directions){
                int i_= dir[0]+i;
                int j_ = dir[1]+j;
                if(i_>=0 and j_>=0 and i_<m and j_<n and board[i_][j_]=='O'){
                    q.push({i_, j_});
                     board[i_][j_]='S';
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }else if(board[i][j]=='S'){
                    board[i][j]= 'O';
                }
            }
        }
    }
};