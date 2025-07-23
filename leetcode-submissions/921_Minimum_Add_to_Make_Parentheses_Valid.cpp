class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
if( not st.empty() and st.top()=='(' and s[i]==')'){
    st.pop();
}else{
    st.push(s[i]);
}
        }
        return st.size();
    }
};