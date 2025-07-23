class Solution {
public:
    int n ;
    int t[100005];
    const int MOD = 1e9+7;
    int solve(int start , string &s, int k){
        if(start>=n) {
            return t[start]=1 ;
        } // our string is exhausted and we finds a one way to make an array 
        if(s[start]=='0') {
            return t[start]= 0 ;
        }
        if(t[start]!=-1) return t[start];
        long long  num =0 ;
        long long  ans = 0 ;
        for(int end = start ;end<n;end++ ){
            num = (num*10)+(s[end]-'0'); //including the last number
            if(num>k) {
                break;
            }
            ans= (ans%MOD+solve(end+1, s, k)%MOD)%MOD; 
        }
        return t[start]=ans ;
    }
    int numberOfArrays(string s, int k) {
         n = s.length();
         memset(t, -1, sizeof(t));
        return solve(0 , s, k);
    }
};