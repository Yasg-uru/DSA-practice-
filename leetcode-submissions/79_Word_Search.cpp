class Solution {
public:
bool helper(vector<vector<char>>&board,string &word,int i,int j,int m,int n,int k){

    //base case 
    if(k>=word.size()){
        return true;
    }
    if(i>=m or j>=n or i<0 or j<0 or board[i][j]=='.' or word[k]!=board[i][j]){

        return false;
    }
    if(word.size()==1 and board[i][j]==word[k]){
        return true;
    }
    board[i][j]='.';
    bool temp=false;
    vector<int>xdir={0,0,1,-1};
    vector<int>ydir={1,-1,0,0};
    //now we have four directions for checking the valid string is present or not
  for(int index=0;index<4;index++){
      temp=temp or helper(board,word,i+xdir[index],j+ydir[index],m,n,k+1);
  }
  board[i][j]=word[k];
  return temp;
}
    bool exist(vector<vector<char>>& board, string word) {
        //now we are using the backtracking algorithm
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(word[0]==board[i][j]){
                    if(helper(board,word,i,j,m,n,0)){
                    return true;
                }
                }
            }
        }
        return false;
    }
};