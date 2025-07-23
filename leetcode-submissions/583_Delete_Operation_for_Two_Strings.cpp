class Solution {
public:
    int m , n ;
    int t[501][501];
    int solve(int i , int j , string& word1, string& word2){
        if(i>=m and j>=n){
            return 0 ;

        }
        if(i>=m or j>=n){
            return abs(i-j);
        }
        if(t[i][j]!=-1){
            return t[i][j];

        }
        if(word1[i]==word2[j]){
            return t[i][j] =  solve(i+1, j+1, word1, word2);
        }else{
            return t[i][j] =  min(solve(i+1, j, word1, word2), solve(i, j+1, word1, word2))+1;
        }

    }
    int minDistance(string word1, string word2) {
         m = word1.size();
         n = word2.size();
         memset(t , -1 , sizeof(t));
        return solve(0  , 0 , word1, word2);

    }
};