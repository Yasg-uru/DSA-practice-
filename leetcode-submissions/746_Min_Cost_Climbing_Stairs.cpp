class Solution {
public:
    int n ;
    int t[1001];
    int solve(vector<int>&cost , int i ){
        if(i>=n) return 0 ;
        if(t[i]!=-1) return t[i];
        int oneStep= cost[i]+solve(cost ,i+1);
        int twoStep = cost[i]+solve(cost , i+2);
        return t[i]= min(twoStep , oneStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        memset(t, -1 , sizeof(t));
        return min(solve(cost , 1),solve(cost , 0 )) ;
    }
};