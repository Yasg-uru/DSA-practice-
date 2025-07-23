class Solution {
public:
    int t[501][501];
    int solve(int i,int steps , int &arrLen){
        if(i>=arrLen || i<0) return 0 ;
        if(t[i][steps]!=-1) return t[i][steps];
        if(steps==0 ){
           if(i==0){
            return 1;
           }else{
            return 0 ;
           }
        } 
        int stay = solve(i, steps-1, arrLen);
        int right = solve(i+1, steps-1, arrLen);
        int left = solve(i-1, steps-1, arrLen);
        return t[i][steps]= stay+right+left;
    }
    int numWays(int steps, int arrLen) {
        memset(t , -1 , sizeof(t));
        return solve(0,steps , arrLen);

    }
};