class Solution {
public:
    int t[101][101];
    int solve(string &s, int l , int r){
        if(t[l][r]!=-1) return t[l][r];
        if(l>r) return 0 ;

        if(l==r){
            return 1; // same character 
        }
        int i=l+1;
        while(i<=r and s[l]==s[i]){
             i++;
        }
        int basic = 1+solve(s, i , r);
        if(i==r+1) return 1;// because we have only same characters 
        int greedy = INT_MAX;

        for(int j=i;j<=r;j++){
            if(s[l]==s[j]){

                int ans = solve(s,i,j-1)+solve(s,j,r);
                greedy = min(greedy, ans);
            }
        }
        return t[l][r]= min(greedy , basic);
    }
    int strangePrinter(string s) {
        memset(t, -1 ,sizeof(t));
        return solve(s, 0 , s.length()-1);
    }
};