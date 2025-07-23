class Solution {
public:
    int n ;
    unordered_map<string , int >dp;
    int solve(int i , string s, int k){
        if(k==0){
            return 0 ;

        }
        if(k<0){
            return INT_MIN;
        }
        if(i<0){
            return 0 ;
        }
        string key =  to_string(s[i]) + "|"+to_string(k);
        if(dp.find(key)!=dp.end()){
            return dp[key];
        }
        int take = INT_MIN;

        if((s[i]-'0')*pow(n-i-1, 2)<=k) {take = 1+solve(i-1, s, k-((s[i]-'0')*pow(n-i-1, 2)));}
        int not_take = solve(i-1, s, k);
        return dp[key]=  max(take , not_take);


    }
    int longestSubsequence(string s, int k) {
        n = s.length();
        dp.clear();
        return solve(n-1 , s, k);
    }
};