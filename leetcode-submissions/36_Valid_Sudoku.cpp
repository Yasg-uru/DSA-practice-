class Solution {
public:
    bool check(vector<vector<char>>&board, int si , int sj, int ei , int ej){
         set<char>st;
        for(int i =si ;i<=ei;i++){
            for(int j =sj;j<=ej;j++){
                 if(board[i][j]=='.') continue;
                if(st.find(board[i][j])!=st.end()){
                    return false;
                }else{
                    st.insert(board[i][j]);
                }
            }
        }
        return true ;
        st.clear();
    }
    bool isValidSudoku(vector<vector<char>>& board) {
     // checking rows 
        for(int i =0 ;i<9;i++){
            // set that tracks the row duplication 
            set<char>st;
            for(int j =0 ;j<9;j++){
                if(board[i][j]=='.') continue;
                if(st.find(board[i][j])!=st.end()){
                    return false;
                }else {
                    st.insert(board[i][j]);
                }
            }
        }
        // now checking columns 
        for(int j =0 ;j<9;j++){
            set<char>st;
            for(int i =0 ;i<9;i++){
                 if(board[i][j]=='.') continue;
                if(st.find(board[i][j])!=st.end()){
                    return false;
                }else{
                    st.insert(board[i][j]);
                }
            }
        }
        
        // now checking the 3*3 grids is this valid or not 
       
        // now we need to store all the coordinates starting(si, sj ) and ending (ei , ej)
        // [[(0 ,0), (2, 2)] , [(0 , 3), (2, 5)] , [(0 ,6) , (2, 8)]]
        //[[(3, 0) ,(5,2)], [(3,3),(5,5)],[(3, 6), (5, 8)]]
        //[[(6, 0), (8, 2)], [(6, 3), (8, 5)] , [(6, 6), (8, 8)]]
       vector<vector<pair<int, int>>> coords = {
    { {0, 0}, {2, 2} }, { {0, 3}, {2, 5} }, { {0, 6}, {2, 8} },
    { {3, 0}, {5, 2} }, { {3, 3}, {5, 5} }, { {3, 6}, {5, 8} },
    { {6, 0}, {8, 2} }, { {6, 3}, {8, 5} }, { {6, 6}, {8, 8} }
};

        for(auto& co: coords){
 int si = co[0].first, sj = co[0].second;
    int ei = co[1].first, ej = co[1].second;
            if(check(board , si , sj , ei , ej)==false){
                return false;
            }
        }
        return true ;
        
    }
};