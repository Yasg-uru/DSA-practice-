class Solution {
public:
    string toLowerCase(string s) {
     string ans="";
     for(int i=0;i<s.size();i++){
         if(isupper(s[i])){
             ans+=tolower(s[i]);

         }else{
             ans+=s[i];

         }
     }
     return ans;   
    }
};