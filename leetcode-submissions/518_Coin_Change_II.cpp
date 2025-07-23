class Solution {
public:
    int n ;    
    int t[301][5001]; 
    int solve(int amount , vector<int>&coins , int  i ){
        if(i>=n) return  0;
        if(t[i][amount]!=-1) return t[i][amount];
        if(amount==0) return 1;

        if(amount<coins[i]){
            return 0 ;

        }
        int take = solve(amount-coins[i], coins, i );
        int not_take = solve(amount , coins, i+1);
        return t[i][amount]= take+not_take;
    }
    int change(int amount, vector<int>& coins) {
        // we can take one coin multiple times 
        n = coins.size();
        memset(t, -1 ,sizeof(t));
        return solve(amount , coins, 0  );

    }
};