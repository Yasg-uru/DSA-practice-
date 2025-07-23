class Solution {
public:
    int solve(int n ){
        if(n==1){
            return 1;

        }
        int maxres= INT_MIN ;

        int prod = 1;
        for(int i=1;i<=n-i;i++){
            prod = i*max(n-i, solve(n-i));
            maxres = max(maxres, prod);
        }
        return maxres;
    }
    int integerBreak(int n) {
        return solve(n);
    }
};