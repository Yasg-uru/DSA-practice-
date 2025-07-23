class Solution {
public:
    vector<vector<string>>dp;
    string solve(string s1, string s2, int i  , int j , int n , int m  ){
        
       if (i == n) return s2.substr(j);
        if (j == m) return s1.substr(i);
    if(not dp[i][j].empty()) return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]= s1[i]+solve(s1, s2, i+1, j+1, n , m );
        }else{
            string takeJ= s2[j]+solve(s1, s2, i, j+1, n , m );
            string takeI= s1[i]+solve(s1, s2, i+1, j, n , m );
            if(takeJ.length()>takeI.length()){
                return dp[i][j]= takeI;
            }else {
                return dp[i][j]=takeJ;
            }
        }
        
    }
    string shortestCommonSupersequence(string str1, string str2) {
        dp.clear();
        int n = str1.length();
        int m = str2.length();
        dp.resize(1002, vector<string>(1002, ""));
        return solve(str1, str2, 0 , 0 ,n , m  );
    }
};