class Solution {
public:
    vector<vector<double>>t;
    double solve(int p , int i , int j){
        if(i<j or i<0 or j<0) return 0.0;
        if(t[i][j]!=-1.0) return t[i][j];
        if(i==0 and j==0) return p ;
        double up_left= (solve(p,i-1,j-1)-1)/2.0;
        double up_right= (solve(p,i-1,j)-1)/2.0;
        if(up_left<0) {up_left= 0.0;}
        if(up_right<0){ up_right= 0.0;}
        return t[i][j]= up_left+up_right;
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        t.clear();
        t.resize(query_row+1, vector<double>(query_glass+1, -1.0));
        
        return min(1.0, solve(poured, query_row, query_glass));

    }
};