class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
       int i=0,j=0;
       for(int i=0;i<str1.size();i++){
        if(str1[i]==str2[j] or (str1[i]=='z' and str2[j]=='a') or (str1[i]+1==str2[j])){
            j++;

        }
       }
       return j==str2.size();
    }
};