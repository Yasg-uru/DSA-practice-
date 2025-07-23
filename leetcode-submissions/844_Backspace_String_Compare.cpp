class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st1;
        if(s.size()!=t.size()){
            return false;
        }
            for(int i=0;i<s.size();i++){
              if(s[i]=='#' and not st1.empty()){
                st1.pop();  
              }else{
                  st1.push(s[i]);
              }
            }
        stack<char>st2;
        for(int i=0;i<t.size();i++){
              if(t[i]=='#' and not st2.empty()){
                st2.pop();  
              }else{
                  st2.push(t[i]);
              }
            }
            return st1.size()==st2.size();


    }
};