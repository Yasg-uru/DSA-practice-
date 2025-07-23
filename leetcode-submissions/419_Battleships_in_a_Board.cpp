class Solution {
public:
    int m , n ;
    vector<vector<int>>directions = {{0 , 1}, {1, 0 }, {0 , -1}, {-1, 0}};
    void BFS(vector<vector<char>>& board, int i , int j){
        queue<pair<int , int >>q;
        q.push({i , j});
        while(not q.empty()){
                int i = q.front().first ;
                int j = q.front().second ;
                q.pop();

                for(auto& dir : directions ){
                    int i_ = dir[0]+i ;
                    int j_ = dir[1]+j;
                    if(i_>=0 and j_>=0 and i_<m and j_<n and board[i_][j_]=='X'){
                        board[i_][j_]= '.';
                        q.push({i_, j_});

                    }
                }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
         m = board.size(), n = board[0].size();
        int count =0 ;
        for(int i=0;i<m ;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='X'){
                    BFS(board, i , j);
                    count++;
                }
            }
        }
        return count ;
    }
};