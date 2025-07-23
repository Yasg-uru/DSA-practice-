class Solution {
public:
    int n ;
    int t[501][501];

    int solve(int i , vector<int>&cost , vector<int>&time,int walls){
        if(walls<=0) {
            return 0 ;
        }
        if(i>=n){
           
            return 1e9;

        }

        
        if(t[i][walls]!=-1) return t[i][walls];
        int paint = cost[i]+solve(i+1, cost , time , walls-1-time[i]);
         int no_paint= solve(i+1, cost ,time , walls);
        return t[i][walls] =  min(paint , no_paint);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        n = time.size();
       for(int i=0;i<501;i++){
       for(int j=0;j<501;j++){
        t[i][j] = -1;
       }
       }

        return solve(0 , cost , time ,time.size());

    }
};