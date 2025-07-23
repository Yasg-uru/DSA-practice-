class Solution {
public:
    int n ;
    int MOD = 1e9+7;
    int t[101][201];
    // time complexity : o(n*fuel*n)->n^2*fuel
    int solve(vector<int>& locations, int curr_index, int &finish, int fuel ){
        if(fuel<0){
            return 0 ;
        }
        if(t[curr_index][fuel]!=-1) return t[curr_index][fuel];
        int ans = 0 ;
        if(curr_index==finish){
            ans=(ans%MOD+1)%MOD;
        }
        //abhi start toh equal ho gaya hai but ham or bhi paths se pahucch sakte hai 
        for(int i=0;i<n;i++){
            if(i!=curr_index){
                ans=(ans%MOD+solve(locations , i , finish,fuel-abs(locations[i]-locations[curr_index]))%MOD)%MOD;

            }
        }
        return t[curr_index][fuel]=ans%MOD ;

    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        n= locations.size();
        memset(t, -1,sizeof(t));
        return solve(locations , start , finish, fuel);

    }
};