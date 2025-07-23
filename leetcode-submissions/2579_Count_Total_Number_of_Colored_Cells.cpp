class Solution {
public:
    int t[100001];
    long long solve(int n ){
         if(t[n]!=-1) return t[n];
         if(n==1) return 1;
        if(n==2){
            return 5 ;
        }
        return t[n]=solve(n-1) + 4*(n-1);
    }
    long long coloredCells(int n) {
        // this question belongs from the dynamic programming concept also 
       memset(t, -1 , sizeof(t));
       return solve(n);
    }
};