class Solution {
public:
    int minimumLength(string s) {
        if(s.size()==1){
            return 1;
        }
        int left=0;
        int right=s.size()-1;
       while(left<right and s[left]==s[right]){
           char leftchar=s[left];
           while(s[left]==leftchar){
               left++;
           }
           char rightchar=s[right];
           while(s[right]==rightchar and right>left){
               right--;
           }

       }
       return right-left+1;
    }
};