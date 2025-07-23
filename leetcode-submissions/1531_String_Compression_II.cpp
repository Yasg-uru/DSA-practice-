class Solution {
public:
    int n ;
    int dp[101][101][29][11]; 
    int solve(string & s , int i , int k , int prevChar,int freq ){
        if(k<0){
            return INT_MAX ;
            //because deletion is more than required
        }
        if(i>=n){
            return 0 ;
        }
        if (dp[i][k][prevChar + 1][freq] != -1)  // prevChar + 1 to handle -1 indexing
           { return dp[i][k][prevChar + 1][freq];}

        int del_i= solve(s, i+1, k-1, prevChar,freq);
        int keep_i= 0 ;
        if(s[i]-'a'!=prevChar){
            //we are seeing first time 
            keep_i = 1+solve(s, i+1, k, s[i]-'a', 1);

        }else{
            int one_more_addition= 0 ;
            if(freq==1 or freq==9 or freq==99){
                one_more_addition= 1;
            }
            keep_i= one_more_addition+solve(s, i+1,k, prevChar, freq+1);
        }
        return dp[i][k][prevChar + 1][freq]= min(keep_i, del_i);


    }
    int getLengthOfOptimalCompression(string s, int k) {
        n = s.length();
         memset(dp, -1, sizeof(dp)); 
        return solve(s, 0 , k, 26,0 );
    }
};