class Solution {
public:
    bool check(string s , int i , int j){
        if(i>=j) return true;
        if(s[i]!=s[j]) return false;
        return check(s, i+1, j-1);

    }
    string longestPalindrome(string s) {
       
        string ans ="";

      
            for(int i=0;i<s.length();i++){
                for(int j=i;j<s.length();j++){
                if (check(s, i, j)) {  // Call recursive check function
                    if (j - i + 1 > ans.length()) {
                        ans = s.substr(i, j - i + 1);
                    }
                }
                }
                }
            
            return ans ;
            
    }
};