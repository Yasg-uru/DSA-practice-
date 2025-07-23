class Solution {
public:
    double t[26][26][101];
    vector<vector<int>>directions ={{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
    double solve(int i , int j, int n ,int k){
        if(i>=n or i<0 or j<0 or j>=n ) return 0 ;
        if(k==0) return 1;
        if(t[i][j][k]!=-1.0) return t[i][j][k];
        double ans =0;
        for(auto& dir :directions){
            int i_= dir[0]+i;
            int j_= dir[1]+j;
            ans+=(double)solve(i_, j_, n,k-1);
        }
        return t[i][j][k]= (double)ans/8.0;

    }
    double knightProbability(int n, int k, int row, int column) {
                for (int i = 0; i < 26; i++)
                    for (int j = 0; j < 26; j++)
                        for (int m = 0; m < 101; m++)
                        t[i][j][m] = -1.0;

        return solve(row ,column, n , k);
    }
};