class Solution {
public:
pair<int , int > getCoordinates(int val , int n ){
    int row_from_top = (val-1)/n;
    int row_from_bottom = (n-1)-row_from_top;
    int col = (val-1)%n;
    if((row_from_bottom%2==0 and n%2==0) or (row_from_bottom%2==1 and n%2==1)){
        col = (n-1)-col;
    }
    return make_pair(row_from_bottom , col);

}
    int snakesAndLadders(vector<vector<int>>& board) {
        int steps = 0 ;
        int n = board.size();
        vector<vector<bool>>visited(n ,vector<bool>(n , false) );
        queue<int>q;
        q.push(1);//starting from one 
        while(not q.empty()){
            int size = q.size();
            while(size--){
                    int x = q.front();
                    q.pop();
                    if(x==n*n){
                        return steps ;
                    }
                    //trying by throwing dice 
                    for(int k = 1;k<=6;k++){
                        int val= x+k;
                        if(val>n*n) continue ;
                        pair<int, int >coord = getCoordinates(val, n );
                        auto [r , c]= coord;
                        if(visited[r][c]==true){
                            continue ;
                        }
                        if(board[r][c]==-1){
                            q.push(val);
                        }else {
                            q.push(board[r][c]);
                        }
                        visited[r][c]= true ;

                    }
            }
            steps++;
        }
        return -1;
    }
};