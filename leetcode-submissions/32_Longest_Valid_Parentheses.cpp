class Solution {
public:
    int longestValidParentheses(string s) {
        int open =0;
        int close = 0;
        int maxAns = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') open++;
            else close++;

            if(open==close){
                maxAns = max(maxAns , open+close);
            }else if (close>open){
                open=close=0;
            }
        }
        open=close=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==')') close++;
            else open++;

            if(open==close){
                maxAns = max(maxAns , open+close);
            }else if (close<open){
                open=close=0;
            }
        }
        return maxAns ;
    }
};