class Solution {
public:
    int N ;
    vector<vector<int>>t;
    int solve(int i , vector<vector<int>>& rides, int pickedEnd){
        if(i>=N){
            return 0 ;
        }
        if(t[i][pickedEnd]!=-1){
            return t[i][pickedEnd];
        }
        int m =0, n=0  , o=0;
        if(pickedEnd<=rides[i][0]){
            m = (rides[i][1]-rides[i][0]+rides[i][2])+solve(i+1,rides, rides[i][1]);
            n = solve(i+1 , rides , pickedEnd);
        }
        o = solve(i+1, rides, pickedEnd);
        return t[i][pickedEnd] = max({m , n , o});


    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
         N = rides.size();
         t.resize(n+1, vector<int>(n+1 ,-1));
         sort(begin(rides), end(rides));
        return solve(0 , rides, 0);
    }
};