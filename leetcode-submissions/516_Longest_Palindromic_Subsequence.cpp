class Solution {
public:
    int solve(string& s , int l , int r){
        if(l>=r) return 0 ;
        if(s[l]==s[r]) return 2+solve(s,l+1, r-1);
        else return max(solve(s,l+1, r), solve(s, l ,r-1));
    }
    int longestPalindromeSubseq(string s) {
        int l= 0 ;
        int r= s.length()-1;

     return solve(s, l , r);

    }
};