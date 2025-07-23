class Solution {
public:
    string reverseWords(string s) {
       int i=0;
       int n=s.size();
       string ans;
       while(i<n){
           while(i<n and s[i]==' '){
               i++;
           }
           if(i>=n){
               break;
           }
           int j=i+1;
           while(j<n and s[j]!=' '){
               j++;
           }
           string res=s.substr(i,j-i);
           if(ans.size()==0){
               ans=res+ans;
           }
           else{
               ans=res+" "+ans;
           }
           i=j+1;
       }
       return ans;
    }
};