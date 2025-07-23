class Solution {
public:
    int t[31][1001];
    const int MOD = 1e9+7;
    int solve(int n , int &k ,int target){
        if(target<0){
            return 0 ;

        }
       if(n==0){
        return target==0;
       }
       if(t[n][target]!=-1){
        return t[n][target];
       }
       int result  =0 ;
       for(int face = 1;face<=k;face++){
        result=(result%MOD+solve(n-1, k ,target-face)%MOD)%MOD;
       }
       return t[n][target]= result;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(t, -1 , sizeof(t));
        return solve(n , k , target);

    }
};