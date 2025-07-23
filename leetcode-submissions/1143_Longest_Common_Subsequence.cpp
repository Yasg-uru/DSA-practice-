class Solution {
public:
vector<vector<int>>dp;

int f(string &a,string &b,int i,int j){
    //base case
    if(i==a.length() || j==b.length() ){
        return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    if(a[i]!=b[j]){
     return dp[i][j]=max(f(a,b,i+1,j),f(a,b,i,j+1));
    }else{
        return dp[i][j]=1+f(a,b,i+1,j+1);

    }
}
    int longestCommonSubsequence(string text1, string text2) {
        dp.clear();
        dp.resize(1005,vector<int>(1005,-1));
        return f(text1,text2,0,0);
    }
};