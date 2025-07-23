class Solution {
public:
bool f(string s,string p,int i,int j,vector<vector<int>>&dp){
    //base case
    if(j==p.size()){
        return i==s.size();
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
  if(p[j+1]=='*' and j+1<p.size()){
      //then we need to check if 
      return dp[i][j]=f(s,p,i,j+2,dp)or(i<s.size() and ((s[i]==p[j] or p[j]=='.'))?f(s,p,i+1,j,dp):false);
  }else if((s[i]==p[j] or p[j]=='.') and i<s.size()){
      return dp[i][j]=f(s,p,i+1,j+1,dp);
  }else{
     return dp[i][j]=false;
  }
}
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size()+1,vector<int>(p.size()+1,-1));
        return f(s,p,0,0,dp);
    }
};