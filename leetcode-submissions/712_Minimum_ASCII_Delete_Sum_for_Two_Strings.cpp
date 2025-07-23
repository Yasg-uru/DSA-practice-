class Solution {
public:
    int m , n ;
    int t[1001][1001];
    int solve(string& s1, string& s2, int i , int  j){
        if(t[i][j]!=-1)return t[i][j];
        if(i>=m and j>=n) return 0 ;
        if(i>=m){
            return s2[j]+solve(s1, s2, i, j+1);

        }
        if(j>=n){
            return s1[i]+solve(s1, s2, i+1, j);

        }
        if(s1[i]==s2[j])
            return solve(s1, s2, i+1, j+1);
        
        
        int del_ith_of_s1 = s1[i]+solve(s1, s2, i+1, j);
        int del_jth_of_s2= s2[j]+solve(s1, s2, i, j+1);
        return t[i][j]= min(del_ith_of_s1,del_jth_of_s2 );
        
    }
    int minimumDeleteSum(string s1, string s2) {
         m = s1.size();
         n = s2.size();
        memset(t, -1 ,sizeof(t));
        return solve(s1, s2, 0 , 0 );

    }
};