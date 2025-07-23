class Solution {
public:
    bool isPalindrome(string s) {
        //now firstly converting all the chracters in lowercase

         int start=0;
         int end=s.size()-1;
         while(start<=end){
             //we have built in function isalnum which checks our charcater is alphanumeric or not
             if(!isalnum(s[start])){
                 start++;
                 continue;
             }
             if(!isalnum(s[end])){
                 end--;
                 continue;
             }
             if(tolower(s[start])!=tolower(s[end])){
                 return false;
             }else{
                 start++;
                 end--;
             }
         }
             return true;
    }
};