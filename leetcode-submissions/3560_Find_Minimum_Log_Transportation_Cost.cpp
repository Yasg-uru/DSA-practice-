class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
       if(n<=k and m<=k) return 0 ;
        int result = INT_MAX;
        if(m<=k){
            for(int i =1;i<n;i++){
                int a = i ;
                int b = n-i;
                if(a<=k and b<=k){
                    result = min(result , a*b);
                }
            }
        }
         if(n<=k){
            for(int i =1;i<m;i++){
                int a = i ;
                int b = n-i;
                if(a<=k and b<=k){
                    result = min(result , a*b);
                }
            }
        }
        return result ;
    }
};