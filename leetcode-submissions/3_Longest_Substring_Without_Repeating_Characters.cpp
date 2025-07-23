class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int length=0;

       for(int i=0;i<s.size();i++){
           for(int j=i+1;j<s.size();j++){
               if(s[i]==s[j]){
                   break;
               }else{
                  length=j-4;
               }
           }
       }
       return length;
    }
};