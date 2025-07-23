class Solution {
public:
   
    int t[101][101][101];
    const int MOD= 1e9+7;
    int solve(int i , int peoples , int currProfit,int& minProfit, vector<int>& group, vector<int>& profit, int& n ){
        // base casess 
        if(peoples>n){
            return  t[i][peoples][currProfit]=0 ;
        }
        
        if(i==group.size()){
            if(currProfit>=minProfit){
                return t[i][peoples][currProfit]= 1;
            }
            return t[i][peoples][currProfit]= 0 ;
        }
        if(t[i][peoples][currProfit]!=-1) return t[i][peoples][currProfit];
        int not_take = solve(i+1, peoples,currProfit, minProfit,group,profit,n)%MOD;
        int take = solve(i+1, peoples+group[i], min(currProfit+profit[i], minProfit),minProfit, group , profit, n)%MOD;
        //  int take = solve(i+1, peoples+group[i], currProfit+profit[i], group , profit, n);
        return t[i][peoples][currProfit]=take+not_take;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
    
   memset(t, -1, sizeof(t));
    return solve( 0 , 0 , 0 ,minProfit, group , profit, n);    
    }
};