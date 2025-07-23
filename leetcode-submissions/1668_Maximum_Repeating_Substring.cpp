class Solution {
public:
    int t[101][101][2];
    int solve(string sequence , string word , int i , int j, bool istake ){
        if(i==sequence.length()){
            return 0 ;
        }
        if(t[i][j][istake]!=-1){
            return t[i][j][istake];
        }
        int res  =0;

        if(sequence[i]==word[j]){
            if(j+1==word.length()){
                res = 1+solve(sequence , word , i+1, 0 , true);
            }else {
                res = solve(sequence , word , i+1, j+1, true );

            }
        }
        if(!istake){
            res = max (res , solve(sequence , word , i+1, 0 , false));
        }
        return t[i][j][istake]=res ; 
    }
    int maxRepeating(string sequence, string word) {
        memset(t , -1 , sizeof(t));
        return solve(sequence , word , 0 , 0 , false );

    }
};