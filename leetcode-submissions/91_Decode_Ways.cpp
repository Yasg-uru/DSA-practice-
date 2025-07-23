class Solution {
public:
    int n ;
    int t[101];

    int solve(string& s, int i ){
        if(t[i]!=-1) {
            return t[i];
        }
        if(i==n){return 1;}
        if(s[i]=='0') {return 0 ;}
        int only_ith_character_and_remaining= solve(s, i+1);
        int ith_character_plus_1= 0 ;
        if(s[i]=='1' or (s[i]=='2' and s[i+1]<='6' and i+1<n)){

        ith_character_plus_1= solve(s, i+2);
        }
        return t[i]=  only_ith_character_and_remaining+ith_character_plus_1;
    }
    int numDecodings(string s) {
        n = s.length();
        memset(t, -1 , sizeof(t));
        return solve(s, 0 );

    }
};