class Solution {
public:
    int minLength(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(not st.empty() and ((s[i]=='B' and st.top()=='A') or (s[i]=='D' and st.top()=='C'))){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        return st.size();
    }
};