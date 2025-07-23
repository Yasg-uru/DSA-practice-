class Solution {
public:
    bool isSubsequence(string s, string t) {
        int count=s.size();
        for(int i=0;i<s.size();i++){
            for(int j=0;j<t.size();j++){
                if(s[i]==t[j]){
                    count--;
                }
            }
        }
        if(count!=0){
            return false;
        }
        return true;
    }
};