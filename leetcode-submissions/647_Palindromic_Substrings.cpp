class Solution {
public:
    bool check(string& s , int i , int j ){
        if(i>j) return true ;
        if(s[i]==s[j]) return check(s, i+1, j-1);
        return false;
    }
    int countSubstrings(string s) {
        int count = 0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(check(s, i, j)){
                    count++;
                }
            }
        }
        return count ;
    }
};