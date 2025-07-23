class Solution {
public:
vector<int>dp;
   int totaltree(int n){
  if(n<=1){
      return 1;

  }
  if(dp[n]!=0){
      return dp[n];
  }
  for(int i=1;i<=n;i++){
      dp[n]+=totaltree(i-1)*totaltree(n-i);

  }
  return dp[n];
   }
    int numTrees(int n) {
dp.clear();
dp.resize(500,0);
     return  totaltree(n);
    }
};